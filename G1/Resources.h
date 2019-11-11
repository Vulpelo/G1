#pragma once

#include "SFML\Audio.hpp"
#include "SFML\Graphics\Texture.hpp"

#include <map>

namespace G1 {

	template <typename T>
	class Resources {
		std::map<std::string, T> resources;

	public:
		/// <summary>
		/// Loads file into memory. 
		/// To access later, use getTexture function and enter its name
		/// Name is a path to texture
		/// </summary>
		void load(const std::string& path) {
			load("", path);
		}

		/// <summary>
		/// Loads file into memory and save under custom name
		/// To access later, use getTexture function and enter its name
		/// </summary>
		void load(const std::string& name, const std::string& path) {
			T resource; resource.loadFromFile(path);
			std::string keyName = name.empty() ? path : name;

			std::map<std::string, T>::iterator resourceIter;
			if ((resourceIter = resources.find(keyName)) != resources.end()) {
				resources.erase(resourceIter);
			}
			resources.emplace(keyName, std::move(resource));
		}

		T& get(const std::string& name) {
			std::map<std::string, T>::iterator resourceIter;
			if ((resourceIter = resources.find(name)) != resources.end()) {
				return resourceIter->second;
			}
			return resources.end()->second;
		}
	};

}
