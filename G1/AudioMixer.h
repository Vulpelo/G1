#pragma once

#ifndef _AUDIO_MIXER_H_
#define _AUDIO_MIXER_H_

#include "AudioGroups.h"
#include <optional>

#include <map>

class AudioMixer {
	//friend class Audio;
public:
	struct GroupSettings {
		float volume = 50;
		GroupSettings(float volume) : volume(volume) {}
	};
private:
	std::map<AudioGroups, GroupSettings> audioGroupSettings;
	std::map<std::string, AudioGroups> audioNameInGroup;

	AudioMixer() {
		audioGroupSettings.insert_or_assign(AudioGroups::DEFAULT, GroupSettings(50));
		audioGroupSettings.insert_or_assign(AudioGroups::MUSIC, GroupSettings(50));
		audioGroupSettings.insert_or_assign(AudioGroups::SFX, GroupSettings(50));
		audioGroupSettings.insert_or_assign(AudioGroups::DIALOGUE, GroupSettings(50));
	}

public:

	static AudioMixer& getInstance() {
		static AudioMixer mixer;
		return mixer;
	}

	void addAudioToGroup(const std::string& audioName, const AudioGroups& group) {
		audioNameInGroup.insert_or_assign(audioName, group);
	}

	void updateGroupSettings(const AudioGroups& group, const GroupSettings& settings) {
		audioGroupSettings.insert_or_assign(group, settings);
	}

	std::optional<GroupSettings> getAudioGroupSettings(const std::string& name) {
		std::optional<GroupSettings> op;

		std::map<std::string, AudioGroups>::iterator itGroup;
		if ( (itGroup = audioNameInGroup.find(name) ) != audioNameInGroup.end() ) {

			std::map<AudioGroups, GroupSettings>::iterator itSetting;
			if ((itSetting = audioGroupSettings.find(itGroup->second)) != audioGroupSettings.end()) {
				op = itSetting->second;
			}
		}
		return op;
	}
};

#endif // !_AUDIO_MIXER_H_
