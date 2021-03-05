/*
    PluginEditor.h
    Copyright (C) 2017 Jonathon Racz, ROLI Ltd.

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

//#include "../JuceLibraryCode/JuceHeader.h"
#include "AudioThumbnailComp.h"
#include "PluginProcessor.h"

class AudioFilePlayerEditor :
    public AudioProcessorEditor,
    private Button::Listener,
    private ChangeListener
{
public:
    AudioFilePlayerEditor(AudioFilePlayerProcessor&);
    ~AudioFilePlayerEditor();

    void paint(Graphics&) override;
    void resized() override;

private:
    AudioFilePlayerProcessor& processor;

    //ScopedPointer<AudioThumbnailComp> thumbnail;//original
    std::unique_ptr<AudioThumbnailComp> thumbnail;//new
    //std::unique_ptr<AudioThumbnailComp> thumbnail(new AudioThumbnailComp(processor.formatManager, processor.transportSource, processor.thumbnailCache, processor.currentlyLoadedFile));
    //AudioThumbnailComp* thumbnail;

    TextButton startStopButton;
    TextButton openButton;

    void buttonClicked(Button* buttonThatWasClicked) override;

    void changeListenerCallback(ChangeBroadcaster* source) override;

    void openButtonClicked();

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AudioFilePlayerEditor)
};
