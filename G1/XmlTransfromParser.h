#pragma once

#ifndef _XML_TRANSFORM_PARSER_H_
#define _XML_TRANSFORM_PARSER_H_

#include "Transform.h"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>

namespace G1 {

	class XmlTransformParser {
	public:
		Transform loadTransform(boost::property_tree::ptree::value_type& val) {
			using namespace boost::property_tree;

			Transform transform;
			BOOST_FOREACH(ptree::value_type &v, val.second.get_child("")) {
				std::string label = v.first;
				if (label == "position") {
					transform.position.x = v.second.get<float>("x", 0.0f);
					transform.position.y = v.second.get<float>("y", 0.0f);
				}
				else if (label == "scale") {
					transform.scale.x = v.second.get<float>("x", 1.0f);
					transform.scale.y = v.second.get<float>("y", 1.0f);
				}
				else if (label == "rotationX") {
					transform.rotationX = val.second.get<float>(label, 0.0f);
				}
			}
			return transform;
		}
	};

}

#endif // !_XML_TRANSFORM_PARSER_H_
