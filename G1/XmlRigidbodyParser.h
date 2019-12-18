#pragma once

#ifndef _XML_RIGIDBODY_PARSER_H_
#define _XML_RIGIDBODY_PARSER_H_

#include "IXmlComponentParser.h"
#include "XmlTransfromParser.h"
#include "XmlPhysicMaterialParser.h"

#include "Rigidbody.h"

#include <boost/foreach.hpp>

namespace G1 {

	class XmlRigidbodyParser : public IXmlComponentParser {
	public:
		Component* load(boost::property_tree::ptree::value_type& val) {
			using namespace boost::property_tree;

			if (val.second.get("<xmlattr>.type", "") == "rectangleCollider") {
				Rigidbody* rb = new Rigidbody();
				BOOST_FOREACH(ptree::value_type &v, val.second.get_child("")) {
					std::string label = v.first;
					if (label == "gravity") {
						rb->setGravity(Vector2(v.second.get<float>("x", 10.0f), v.second.get<float>("y", 10.0f)));
					}
					else if (label == "velocity") {
						rb->setVelocity(Vector2(v.second.get<float>("x", 10.0f), v.second.get<float>("y", 10.0f)));
					}
					else if (label == "mass") {
						rb->setMass(val.second.get<float>(label, 1.f));
					}
					else if (label == "drag") {
						rb->setDrag(val.second.get<float>(label, 0.f));
					}
				}
				return rb;
			}
			return NULL;
		}
	};

}


#endif // !_XML_RIGIDBODY_PARSER_H_
