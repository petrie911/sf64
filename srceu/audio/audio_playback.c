// No version differences found here.

#include "sys.h"
#include "sf64audio_provisional.h"

extern u32 D_80157EF8;
extern u8 sSamplesPerWavePeriod[4];

void func_80011C38(Note* note, f32 arg1);
void func_80013B4C(AdsrState* adsr, EnvelopePoint* envelope, s16* arg2);
void func_8001413C(SequenceChannel* channel);
void func_8001266C(SequenceLayer* layer);
f32 func_80013B70(AdsrState* adsr);
void func_80012C20(Note* note);
void func_800139F8(Note* note);
void func_80012BE0(AudioListItem* item1, AudioListItem* item2);
void func_80012CCC(Note* note, SequenceLayer* layer);
void func_80013A64(Note* note);
void func_8001459C(AudioListItem* list, AudioListItem* item);
void* func_800145DC(AudioListItem* list);

void func_80011870(Note* note, NoteAttributes* noteAttr) {
    NoteSubEu* noteSub;
    f32 panVolumeLeft;
    f32 pamVolumeRight;
    f32 velocity;
    s32 temp_t0;
    s32 var_a0;
    s32 strongRight;
    s32 strongLeft;
    u8 pan;
    u8 reverb;
    Stereo stereo;

    func_80011C38(note, noteAttr->freqMod);
    noteSub = &note->noteSubEu;
    velocity = noteAttr->velocity;
    pan = noteAttr->pan;
    reverb = noteAttr->reverb;
    stereo = noteAttr->stereo;
    pan %= ARRAY_COUNTU(gHeadsetPanVolume);
    if ((noteSub->bitField0.stereoHeadsetEffects) && (gAudioSoundMode == SOUNDMODE_HEADSET)) {
        var_a0 = pan >> 1;
        if (var_a0 >= ARRAY_COUNT(gHaasEffectDelaySizes)) {
            var_a0 = ARRAY_COUNT(gHaasEffectDelaySizes) - 1;
        }
        noteSub->rightDelaySize = gHaasEffectDelaySizes[var_a0];
        noteSub->leftDelaySize = gHaasEffectDelaySizes[ARRAY_COUNT(gHaasEffectDelaySizes) - 1 - var_a0];
        noteSub->bitField0.stereoStrongRight = false;
        noteSub->bitField0.stereoStrongLeft = false;
        noteSub->bitField0.usesHeadsetPanEffects = true;

        panVolumeLeft = gHeadsetPanVolume[pan];
        pamVolumeRight = gHeadsetPanVolume[ARRAY_COUNT(gHeadsetPanVolume) - 1 - pan];
    } else if (noteSub->bitField0.stereoHeadsetEffects && (gAudioSoundMode == SOUNDMODE_STEREO)) {
        noteSub->leftDelaySize = 0;
        noteSub->rightDelaySize = 0;
        noteSub->bitField0.usesHeadsetPanEffects = false;

        panVolumeLeft = gStereoPanVolume[pan];
        pamVolumeRight = gStereoPanVolume[ARRAY_COUNT(gStereoPanVolume) - 1 - pan];
        strongRight = false;
        strongLeft = false;
        if (pan < 32) {
            strongLeft = true;
        } else if (pan > 96) {
            strongRight = true;
        }
        noteSub->bitField0.stereoStrongRight = strongRight;
        noteSub->bitField0.stereoStrongLeft = strongLeft;
        switch (stereo.s.bit2) {
            case 0:
                noteSub->bitField0.stereoStrongRight = stereo.s.strongRight;
                noteSub->bitField0.stereoStrongLeft = stereo.s.strongLeft;
                break;
            case 1:
                break;
            case 2:
                noteSub->bitField0.stereoStrongRight = stereo.s.strongRight | strongRight;
                noteSub->bitField0.stereoStrongLeft = stereo.s.strongLeft | strongLeft;
                break;
            case 3:
                noteSub->bitField0.stereoStrongRight = stereo.s.strongRight ^ strongRight;
                noteSub->bitField0.stereoStrongLeft = stereo.s.strongLeft ^ strongLeft;
                break;
        }
    } else if (gAudioSoundMode == SOUNDMODE_MONO) {
        panVolumeLeft = 0.707f;
        pamVolumeRight = 0.707f;
    } else {
        panVolumeLeft = gDefaultPanVolume[pan];
        pamVolumeRight = gDefaultPanVolume[ARRAY_COUNT(gDefaultPanVolume) - 1 - pan];
    }
    if (velocity < 0.0f) {
        velocity = 0.0f;
    }
    if (velocity > 1.0f) {
        velocity = 1.0f;
    }
    noteSub->panVolLeft = (s32) (velocity * panVolumeLeft * 4095.999f);
    noteSub->panVolRight = (s32) (velocity * pamVolumeRight * 4095.999f);
    noteSub->gain = noteAttr->gain;
    if (noteSub->reverb != reverb) {
        noteSub->reverb = reverb;
        noteSub->bitField0.unused = true;
    } else if (noteSub->bitField0.needsInit) {
        noteSub->bitField0.unused = true;
    } else {
        noteSub->bitField0.unused = false;
    }
}

void func_80011C38(Note* note, f32 arg1) {
    NoteSubEu* noteSub = &note->noteSubEu;
    f32 var_fv0;

    if (arg1 < 2.0f) {
        noteSub->bitField1.hasTwoParts = 0;
        if (arg1 > 1.99998f) {
            var_fv0 = 1.99998f;
        } else {
            var_fv0 = arg1;
        }
    } else {
        noteSub->bitField1.hasTwoParts = 1;
        if (arg1 > 3.99996f) {
            var_fv0 = 1.99998f;
        } else {
            var_fv0 = arg1 * 0.5f;
        }
    }
    note->noteSubEu.resampleRate = (s32) (var_fv0 * 32768.0f);
}

TunedSample* func_80011CF0(Instrument* instrument, s32 arg1) {
    TunedSample* sample;

    if (arg1 < instrument->normalRangeLo) {
        sample = &instrument->lowPitchTunedSample;
    } else if (arg1 <= instrument->normalRangeHi) {
        sample = &instrument->normalPitchTunedSample;
    } else {
        sample = &instrument->highPitchTunedSample;
    }
    return sample;
}

Instrument* Audio_GetInstrument(s32 fontId, s32 instId) {
    Instrument* instrument;

    if ((gFontLoadStatus[fontId] < 2) != 0) {
        D_80157EF8 = fontId + 0x10000000;
        return NULL;
    }
    if (instId >= gSoundFontList[fontId].numInstruments) {
        D_80157EF8 = (fontId << 8) + instId + 0x03000000;
        return NULL;
    }
    instrument = gSoundFontList[fontId].instruments[instId];
    if (instrument == NULL) {
        D_80157EF8 = (fontId << 8) + instId + 0x01000000;
        return instrument;
    }
    return instrument;
}

Drum* Audio_GetDrum(s32 fontId, s32 drumId) {
    Drum* drum;

    if ((gFontLoadStatus[fontId] < 2) != 0) {
        D_80157EF8 = fontId + 0x10000000;
        return NULL;
    }
    if (drumId >= gSoundFontList[fontId].numDrums) {
        D_80157EF8 = (fontId << 8) + drumId + 0x04000000;
        return NULL;
    }
    if ((u32) gSoundFontList[fontId].drums < AUDIO_RELOCATED_ADDRESS_START) {
        return NULL;
    }
    drum = gSoundFontList[fontId].drums[drumId];
    if (gSoundFontList[fontId].drums[drumId] == NULL) {
        D_80157EF8 = (fontId << 8) + drumId + 0x05000000;
    }
    return drum;
}

void func_80011E98(Note* note) {
    if (note->playbackState.parentLayer->adsr.decayIndex == 0) {
        func_80013B4C(&note->playbackState.adsr, note->playbackState.parentLayer->channel->adsr.envelope,
                      &note->playbackState.adsrVolModUnused);
    } else {
        func_80013B4C(&note->playbackState.adsr, note->playbackState.parentLayer->adsr.envelope,
                      &note->playbackState.adsrVolModUnused);
    }
    note->playbackState.adsr.state = 1;
    note->noteSubEu = gDefaultNoteSub;
}

void func_80011F2C(Note* note) {
    if (note->noteSubEu.bitField0.needsInit == 1) {
        note->noteSubEu.bitField0.needsInit = 0;
    }
    note->playbackState.priority = 0;
    note->playbackState.unk_04 = 0;
    note->noteSubEu.bitField0.enabled = 0;
    note->playbackState.parentLayer = NO_LAYER;
    note->playbackState.prevParentLayer = NO_LAYER;
    note->noteSubEu.bitField0.finished = 0;
    note->playbackState.adsr.state = 0;
    note->playbackState.adsr.current = 0.0f;
}

void func_80011F88(void) {
    s32 pad2;
    s32 pad;
    Note* note;
    NotePlaybackState* playbackState;
    NoteSubEu* noteSub;
    NoteAttributes* attr;
    s32 i;
    NoteAttributes sp70;
    u8 bookOffset;
    f32 temp_fs0;

    for (i = 0; i < gNumNotes; i++) {
        note = &gNotes[i];

        playbackState = &note->playbackState;
        if ((playbackState->parentLayer != NO_LAYER)) {
            if ((u32) playbackState->parentLayer < 0x7FFFFFFF) {
                continue;
            }

            if ((note != playbackState->parentLayer->note) && (playbackState->unk_04 == 0)) {
                playbackState->adsr.action.asByte |= 0x10;
                playbackState->adsr.fadeOutVel = gAudioBufferParams.ticksPerUpdateInv;
                playbackState->priority = 1;
                playbackState->unk_04 = 2;
                goto block_21;
            } else {
                if ((playbackState->parentLayer->enabled) || (playbackState->unk_04 != 0) ||
                    (playbackState->priority <= 0)) {
                    if (playbackState->parentLayer->channel->seqPlayer == NULL) {
                        func_8001413C(playbackState->parentLayer->channel);
                        playbackState->priority = 1;
                        playbackState->unk_04 = 1;
                        continue;
                    }
                    if (!(playbackState->parentLayer->channel->seqPlayer->muted &&
                          (playbackState->parentLayer->channel->muteBehavior & 0x40))) {
                        goto block_21;
                    }
                }
                func_8001266C(playbackState->parentLayer);
                func_80012C20(note);
                func_80012BE0(&note->listItem.pool->decaying, &note->listItem);
                playbackState->priority = 1;
                playbackState->unk_04 = 2;
            }
        } else if ((playbackState->unk_04 == 0) && (playbackState->priority > 0)) {
            continue;
        }
    block_21:

        if (playbackState->priority != 0) {
            if (1) {}
            noteSub = &note->noteSubEu;
            if ((playbackState->unk_04 > 0) || noteSub->bitField0.finished) {
                if ((playbackState->adsr.state == 0) || noteSub->bitField0.finished) {
                    if (playbackState->wantedParentLayer != NO_LAYER) {
                        func_80011F2C(note);
                        if (playbackState->wantedParentLayer->channel != NULL) {
                            func_80012CCC(note, playbackState->wantedParentLayer);
                            func_80013A64(note);
                            func_80012C20(note);
                            func_8001459C(&note->listItem.pool->active, &note->listItem);
                            playbackState->wantedParentLayer = NO_LAYER;
                        } else {
                            func_80011F2C(note);
                            func_80012C20(note);
                            func_8001459C(&note->listItem.pool->disabled, &note->listItem);
                            playbackState->wantedParentLayer = NO_LAYER;
                            goto next;
                        }
                    } else {
                        func_80011F2C(note);
                        func_80012C20(note);
                        func_8001459C(&note->listItem.pool->disabled, &note->listItem);
                        goto next;
                    }
                }
            } else if (playbackState->adsr.state == 0) {
                func_80011F2C(note);
                func_80012C20(note);
                func_8001459C(&note->listItem.pool->disabled, &note->listItem);
                goto next;
            }

            temp_fs0 = func_80013B70(&playbackState->adsr);
            func_800139F8(note);
            attr = &playbackState->attributes;
            if ((playbackState->unk_04 == 1) || (playbackState->unk_04 == 2)) {
                sp70.freqMod = attr->freqMod;
                sp70.velocity = attr->velocity;
                sp70.pan = attr->pan;
                sp70.reverb = attr->reverb;
                sp70.stereo = attr->stereo;
                sp70.gain = attr->gain;
                bookOffset = noteSub->bitField1.bookOffset;
            } else {
                sp70.freqMod = playbackState->parentLayer->noteFreqMod;
                sp70.velocity = playbackState->parentLayer->noteVelocity;
                sp70.pan = playbackState->parentLayer->notePan;
                sp70.stereo = playbackState->parentLayer->stereo;
                sp70.reverb = playbackState->parentLayer->channel->targetReverbVol;
                sp70.gain = playbackState->parentLayer->channel->reverbIndex;

                bookOffset = playbackState->parentLayer->channel->bookOffset % 8U;
                if ((playbackState->parentLayer->channel->seqPlayer->muted) &&
                    (playbackState->parentLayer->channel->muteBehavior & 8)) {
                    sp70.freqMod = 0.0f;
                    sp70.velocity = 0.0f;
                }
            }
            sp70.freqMod *= playbackState->vibratoFreqMod * playbackState->portamentoFreqMod;
            sp70.freqMod *= gAudioBufferParams.resampleRate;
            sp70.velocity *= temp_fs0;
            func_80011870(note, &sp70);
            noteSub->bitField1.bookOffset = bookOffset;
        next:;
        }
    }
}

void func_80012418(SequenceLayer* layer, s32 arg1) {
    Note* note;
    NoteAttributes* noteAttr;

    if (layer == NO_LAYER) {
        return;
    }
    layer->unk_3 = 0;
    if (layer->note == NULL) {
        return;
    }
    note = layer->note;
    if (layer == note->playbackState.wantedParentLayer) {
        note->playbackState.wantedParentLayer = NO_LAYER;
    }

    if (layer != note->playbackState.parentLayer) {
        if ((note->playbackState.parentLayer == NO_LAYER) && (note->playbackState.wantedParentLayer == NO_LAYER) &&
            (layer == note->playbackState.prevParentLayer) && (arg1 != 6)) {
            note->playbackState.adsr.fadeOutVel = gAudioBufferParams.ticksPerUpdateInv;
            note->playbackState.adsr.action.asByte |= 0x10;
        }
    } else {
        noteAttr = &note->playbackState.attributes;
        if (note->playbackState.adsr.state != 6) {
            noteAttr->freqMod = layer->noteFreqMod;
            noteAttr->velocity = layer->noteVelocity;
            noteAttr->pan = layer->notePan;
            noteAttr->stereo = layer->stereo;
            if (layer->channel != NULL) {
                noteAttr->reverb = layer->channel->targetReverbVol;
                noteAttr->gain = layer->channel->reverbIndex;
                if (layer->channel->seqPlayer->muted && (layer->channel->muteBehavior & 8)) {
                    note->noteSubEu.bitField0.finished = 1;
                }
            }
            note->playbackState.priority = 1;
            note->playbackState.prevParentLayer = note->playbackState.parentLayer;
            note->playbackState.parentLayer = NO_LAYER;

            if (arg1 == 7) {
                note->playbackState.adsr.fadeOutVel = gAudioBufferParams.ticksPerUpdateInv;
                note->playbackState.adsr.action.asByte |= 0x10;
                note->playbackState.unk_04 = 2;

            } else {
                note->playbackState.unk_04 = 1;
                note->playbackState.adsr.action.asByte |= 0x20;
                if (layer->adsr.decayIndex == 0) {
                    note->playbackState.adsr.fadeOutVel =
                        layer->channel->adsr.decayIndex * gAudioBufferParams.ticksPerUpdateInvScaled;
                } else {
                    note->playbackState.adsr.fadeOutVel =
                        layer->adsr.decayIndex * gAudioBufferParams.ticksPerUpdateInvScaled;
                }
                note->playbackState.adsr.sustain =
                    (s32) layer->channel->adsr.sustain * note->playbackState.adsr.current / 256.0f;
            }
        }
        if (arg1 == 6) {
            func_80012C20(note);
            func_80012BE0(&note->listItem.pool->decaying, &note->listItem);
        }
    }
}

void func_8001264C(SequenceLayer* layer) {
    func_80012418(layer, 6);
}

void func_8001266C(SequenceLayer* layer) {
    func_80012418(layer, 7);
}

s32 func_8001268C(Note* note, SequenceLayer* layer, s32 waveId) {
    f32 freqMod;
    u8 harmonicIndex = 0;

    if (waveId < 128) {
        waveId = 128;
    }
    freqMod = layer->freqMod;
    if ((layer->portamento.mode != 0) && (layer->portamento.extent > 0.0f)) {
        freqMod *= layer->portamento.extent + 1.0f;
    }
    if (freqMod < 1.0f) {
        freqMod = 1.0465f;
    } else if (freqMod < 2.0f) {
        harmonicIndex = 1;
        freqMod = 0.52325f;
    } else if (freqMod < 4.0f) {
        harmonicIndex = 2;
        freqMod = 0.26263f;
    } else {
        harmonicIndex = 3;
        freqMod = 0.13081f;
    }

    layer->freqMod *= freqMod;
    note->playbackState.waveId = waveId;
    note->playbackState.harmonicIndex = harmonicIndex;
    note->noteSubEu.waveSampleAddr = &gWaveSamples[waveId - 128][harmonicIndex * 64];
    return harmonicIndex;
}

void func_80012790(Note* note, SequenceLayer* layer) {
    s32 harmonicIndex;
    s32 waveId;

    waveId = layer->instOrWave;
    if (waveId == 0xFF) {
        waveId = layer->channel->instOrWave;
    }
    harmonicIndex = note->playbackState.harmonicIndex;
    note->synthesisState.samplePosInt =
        (note->synthesisState.samplePosInt * sSamplesPerWavePeriod[func_8001268C(note, layer, waveId)]) /
        sSamplesPerWavePeriod[harmonicIndex];
}

void func_80012834(AudioListItem* item) {
    item->prev = item;
    item->next = item;
    item->u.value = NULL;
}

void func_80012844(NotePool* pool) {
    func_80012834(&pool->disabled);
    func_80012834(&pool->decaying);
    func_80012834(&pool->releasing);
    func_80012834(&pool->active);
    pool->disabled.pool = pool;
    pool->decaying.pool = pool;
    pool->releasing.pool = pool;
    pool->active.pool = pool;
}

void func_80012894(void) {
    s32 i;

    func_80012844(&gNoteFreeLists);
    for (i = 0; i < gNumNotes; i++) {
        gNotes[i].listItem.u.value = &gNotes[i];
        gNotes[i].listItem.prev = NULL;
        func_8001459C(&gNoteFreeLists.disabled, &gNotes[i].listItem);
    }
}

void func_80012944(NotePool* pool) {
    s32 poolType;
    AudioListItem* poolItem;
    AudioListItem* nextPoolItem;
    AudioListItem* freeList;

    for (poolType = 0; poolType < 4; poolType++) {
        switch (poolType) {
            case 0:
                poolItem = &pool->disabled;
                freeList = &gNoteFreeLists.disabled;
                break;
            case 1:
                poolItem = &pool->decaying;
                freeList = &gNoteFreeLists.decaying;
                break;
            case 2:
                poolItem = &pool->releasing;
                freeList = &gNoteFreeLists.releasing;
                break;
            case 3:
                poolItem = &pool->active;
                freeList = &gNoteFreeLists.active;
                break;
        }

        while (true) {
            nextPoolItem = poolItem->next;
            if ((nextPoolItem == poolItem) || (nextPoolItem == NULL)) {
                break;
            }
            func_80012C20((Note*) nextPoolItem);
            func_8001459C(freeList, nextPoolItem);
        }
    }
}

void func_80012AA4(NotePool* pool, s32 arg1) {
    s32 var_s0;
    s32 poolType;
    AudioListItem* note;
    AudioListItem* freeList;
    AudioListItem* poolList;

    func_80012944(pool);
    poolType = 0;
    var_s0 = 0;
    while (var_s0 < arg1) {
        if (poolType == 4) {
            return;
        }
        switch (poolType) {
            case 0:
                freeList = &gNoteFreeLists.disabled;
                poolList = &pool->disabled;
                break;
            case 1:
                freeList = &gNoteFreeLists.decaying;
                poolList = &pool->decaying;
                break;
            case 2:
                freeList = &gNoteFreeLists.releasing;
                poolList = &pool->releasing;
                break;
            case 3:
                freeList = &gNoteFreeLists.active;
                poolList = &pool->active;
                break;
        }
        while (var_s0 < arg1) {
            note = func_800145DC(freeList);
            if (note == NULL) {
                break;
            }
            func_8001459C(poolList, note);
            var_s0++;
        }
        poolType++;
    }
}

void func_80012BE0(AudioListItem* item1, AudioListItem* item2) {
    if (item2->prev == NULL) {
        item2->prev = item1;
        item2->next = item1->next;
        item1->next->prev = item2;
        item1->next = item2;
        item1->u.count++;
        item2->pool = item1->pool;
    }
}

void func_80012C20(Note* note) {
    if (note->listItem.prev != NULL) {
        note->listItem.prev->next = note->listItem.next;
        note->listItem.next->prev = note->listItem.prev;
        note->listItem.prev = NULL;
    }
}

Note* func_80012C4C(AudioListItem* item, s32 priority) {
    AudioListItem* priorityItem;
    AudioListItem* nextItem = item->next;

    if (nextItem == item) {
        return NULL;
    }
    priorityItem = nextItem;
    for (nextItem; nextItem != item; nextItem = nextItem->next) {
        if (((Note*) nextItem->u.value)->playbackState.priority <=
            ((Note*) priorityItem->u.value)->playbackState.priority) {
            priorityItem = nextItem;
        }
    }

    if (priorityItem == NULL) {
        return NULL;
    }

    if (((Note*) priorityItem->u.value)->playbackState.priority >= priority) {
        return NULL;
    }
    return (Note*) priorityItem->u.value;
}

void func_80012CCC(Note* note, SequenceLayer* layer) {
    s32 pad[4];
    s32 var_a2;
    NoteSubEu* noteSub;

    note->playbackState.prevParentLayer = NO_LAYER;
    note->playbackState.parentLayer = layer;
    note->playbackState.priority = layer->channel->notePriority;
    layer->ignoreDrumPan = 1;
    layer->unk_3 = 3;
    layer->note = note;
    layer->channel->noteUnused = note;
    layer->channel->layerUnused = layer;
    layer->noteVelocity = 0.0f;
    func_80011E98(note);
    var_a2 = layer->instOrWave;
    noteSub = &note->noteSubEu;
    if (var_a2 == 0xFF) {
        var_a2 = layer->channel->instOrWave;
    }
    noteSub->waveSampleAddr = (s16*) layer->tunedSample;
    if (var_a2 >= 128) {
        noteSub->bitField1.isSyntheticWave = true;
    } else {
        noteSub->bitField1.isSyntheticWave = false;
    }
    if (noteSub->bitField1.isSyntheticWave) {
        func_8001268C(note, layer, var_a2);
    }
    note->playbackState.fontId = layer->channel->fontId;
    noteSub->bitField0.stereoHeadsetEffects = layer->channel->stereoHeadsetEffects;
    noteSub->bitField1.reverbIndex = layer->channel->someOtherPriority & 3;
}

void func_80012E08(Note* note, SequenceLayer* layer) {
    func_8001266C(note->playbackState.parentLayer);
    note->playbackState.wantedParentLayer = layer;
}

void func_80012E3C(Note* note, SequenceLayer* layer) {
    note->playbackState.wantedParentLayer = layer;
    note->playbackState.priority = layer->channel->notePriority;
    note->playbackState.adsr.fadeOutVel = gAudioBufferParams.ticksPerUpdateInv;
    note->playbackState.adsr.action.asByte |= 0x10;
}

Note* func_80012E68(NotePool* pool, SequenceLayer* layer) {
    Note* note = func_800145DC(&pool->disabled);

    if (note != NULL) {
        func_80012CCC(note, layer);
        func_80012BE0(&pool->active, &note->listItem);
    }
    return note;
}

Note* func_80012EB4(NotePool* pool, SequenceLayer* layer) {
    Note* note = func_800145DC(&pool->decaying);

    if (note != NULL) {
        func_80012E3C(note, layer);
        func_8001459C(&pool->releasing, &note->listItem);
    }
    return note;
}

Note* func_80012F04(NotePool* pool, SequenceLayer* layer) {
    Note* sp34;
    Note* sp30;
    s32 sp2C;
    s32 sp28;

    sp2C = sp28 = 0x10;
    sp34 = func_80012C4C(&pool->releasing, layer->channel->notePriority);
    if (sp34 != NULL) {
        sp2C = sp34->playbackState.priority;
    }
    sp30 = func_80012C4C(&pool->active, layer->channel->notePriority);
    if (sp30 != NULL) {
        sp28 = sp30->playbackState.priority;
    }
    if ((sp34 == NULL) && (sp30 == NULL)) {
        return NULL;
    }
    if (sp28 < sp2C) {
        func_80012C20(sp30);
        func_80012E08(sp30, layer);
        func_8001459C(&pool->releasing, &sp30->listItem);
        sp30->playbackState.priority = layer->channel->notePriority;
        return sp30;
    } else {
        sp34->playbackState.wantedParentLayer = layer;
        sp34->playbackState.priority = layer->channel->notePriority;
        return sp34;
    }
}

Note* func_80012FFC(SequenceLayer* layer) {
    Note* sp24;

    if (layer->channel->noteAllocPolicy & 1) {
        sp24 = layer->note;
        if ((sp24 != NULL) && (layer == sp24->playbackState.prevParentLayer) &&
            (sp24->playbackState.wantedParentLayer == NO_LAYER)) {

            func_80012E3C(sp24, layer);
            func_80012C20(sp24);
            func_8001459C(&sp24->listItem.pool->releasing, &sp24->listItem);
            return sp24;
        }
    }

    if (layer->channel->noteAllocPolicy & 2) {
        if (((sp24 = func_80012E68(&layer->channel->notePool, layer)) != NULL) ||
            ((sp24 = func_80012EB4(&layer->channel->notePool, layer)) != NULL) ||
            ((sp24 = func_80012F04(&layer->channel->notePool, layer)) != NULL)) {
            return sp24;
        }
    } else if (layer->channel->noteAllocPolicy & 4) {
        if (((sp24 = func_80012E68(&layer->channel->notePool, layer)) != NULL) ||
            ((sp24 = func_80012E68(&layer->channel->seqPlayer->notePool, layer)) != NULL) ||
            ((sp24 = func_80012EB4(&layer->channel->notePool, layer)) != NULL) ||
            ((sp24 = func_80012EB4(&layer->channel->seqPlayer->notePool, layer)) != NULL) ||
            ((sp24 = func_80012F04(&layer->channel->notePool, layer)) != NULL) ||
            ((sp24 = func_80012F04(&layer->channel->seqPlayer->notePool, layer)) != NULL)) {
            return sp24;
        }
    } else if (layer->channel->noteAllocPolicy & 8) {
        if (((sp24 = func_80012E68(&gNoteFreeLists, layer)) != NULL) ||
            ((sp24 = func_80012EB4(&gNoteFreeLists, layer)) != NULL) ||
            ((sp24 = func_80012F04(&gNoteFreeLists, layer)) != NULL)) {
            return sp24;
        }
    } else {
        if (((sp24 = func_80012E68(&layer->channel->notePool, layer)) != NULL) ||
            ((sp24 = func_80012E68(&layer->channel->seqPlayer->notePool, layer)) != NULL) ||
            ((sp24 = func_80012E68(&gNoteFreeLists, layer)) != NULL) ||
            ((sp24 = func_80012EB4(&layer->channel->notePool, layer)) != NULL) ||
            ((sp24 = func_80012EB4(&layer->channel->seqPlayer->notePool, layer)) != NULL) ||
            ((sp24 = func_80012EB4(&gNoteFreeLists, layer)) != NULL) ||
            ((sp24 = func_80012F04(&layer->channel->notePool, layer)) != NULL) ||
            ((sp24 = func_80012F04(&layer->channel->seqPlayer->notePool, layer)) != NULL) ||
            ((sp24 = func_80012F04(&gNoteFreeLists, layer)) != NULL)) {
            return sp24;
        }
    }
    layer->unk_3 = 0;
    return NULL;
}

void func_800132C8(void) {
    s32 i;
    Note* note;

    for (i = 0; i < gNumNotes; i++) {
        note = &gNotes[i];

        note->noteSubEu = gZeroNoteSub;

        note->playbackState.priority = 0;
        note->playbackState.unk_04 = 0;
        note->playbackState.parentLayer = NO_LAYER;
        note->playbackState.wantedParentLayer = NO_LAYER;
        note->playbackState.prevParentLayer = NO_LAYER;
        note->playbackState.waveId = 0;
        note->playbackState.attributes.velocity = 0.0f;
        note->playbackState.adsrVolModUnused = 0;
        note->playbackState.adsr.state = 0;
        note->playbackState.adsr.action.asByte = 0;
        note->playbackState.vibratoState.active = 0;
        note->playbackState.portamento.cur = 0.0f;
        note->playbackState.portamento.speed = 0.0f;

        note->synthesisState.synthesisBuffers = AudioHeap_Alloc(&gMiscPool, sizeof(Note));
    }
}
