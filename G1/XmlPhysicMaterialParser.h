#pragma once

#ifndef _XML_PHYSICS_MATERIAL_PARSER_H_
#define _XML_PHYSICS_MATERIAL_PARSER_H_

#include "Collider.h"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>

namespace G1 {

	class XmlPhysicsMaterialParser {
		Combine combineFromString(std::string combineString) {
			if (combineString == "MAXIMUM")
				return Combine::MAXIMUM;
			if (combineString == "MINIMUM")
				return Combine::MINIMUM;
			if (combineString == "AVERAGE")
				return Combine::AVERAGE;
			if (combineString == "MULTIPLY")
				return Combine::MULTIPLY;
			return Combine::AVERAGE;
		}

	public:
		PhysicMaterial loadPhysicMaterial(boost::property_tree::ptree::value_type& val) {
			using namespace boost::property_tree;

			PhysicMaterial pm;
			BOOST_FOREACH(ptree::value_type &v, val.second.get_child("")) {
				std::string label = v.first;
				if (label == "frictionCombine") {
					std::string type = val.second.get<std::string>(label, "AVERAGE");
					pm.frictionCombine = combineFromString(type);
				}
				else if (label == "bouncyCombine") {
					std::string type = val.second.get<std::string>(label, "MAXIMUM");
					pm.bouncyCombine = combineFromString(type);
				}
				else if (label == "friction") {
					pm.friction = val.second.get<float>(label, 0.0f);
				}
				else if (label == "bounciness") {
					pm.bounciness = val.second.get<float>(label, 0.0f);
				}
			}
			return pm;
		}
	};

}


#endif // !_XML_PHYSICS_MATERIAL_PARSER_H_
