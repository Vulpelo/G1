#pragma once

#ifndef _XML_SPRITE_PARSER_H_
#define _XML_SPRITE_PARSER_H_

#include "IXmlComponentParser.h"
#include "Sprite.h"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>

namespace G1 {

	class XmlSpriteParser : public IXmlComponentParser {
	public:
		Component* load(boost::property_tree::ptree::value_type& val) {
			using namespace boost::property_tree;

			if ( val.second.get("<xmlattr>.type", "") == "sprite" ) {
				std::string texture;
				Vector2 startPosition;
				Vector2 imageSize;
				BOOST_FOREACH(ptree::value_type &v, val.second.get_child("")) {
					std::string label = v.first;
					if (label == "texture") {
						texture = val.second.get<std::string>(label, "");
					}
					else if (label == "imageSize") {
						imageSize.x = v.second.get<float>("x", 10.0f);
						imageSize.y = v.second.get<float>("y", 10.0f);
					}
					else if (label == "startPosition") {
						startPosition.x = v.second.get<float>("x", 0.0f);
						startPosition.y = v.second.get<float>("y", 0.0f);
					}
				}
				return new Sprite(Assets::getInstance().textures().get(texture), imageSize, startPosition);
			}
			return NULL;
		}
	};

}


#endif // !_XML_SPRITE_PARSER_H_
