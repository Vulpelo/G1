#pragma once

#ifndef _XML_RECTANGLE_COLLIDER_PARSER_H_
#define _XML_RECTANGLE_COLLIDER_PARSER_H_

#include "IXmlComponentParser.h"
#include "RectangleCollider.h"
#include "XmlTransfromParser.h"
#include "XmlPhysicMaterialParser.h"

#include <boost/foreach.hpp>

namespace G1 {

	class XmlRectangleColliderParser : public IXmlComponentParser {
	public:
		Component* load(boost::property_tree::ptree::value_type& val) {
			using namespace boost::property_tree;

			if (val.second.get("<xmlattr>.type", "") == "rectangleCollider") {
				RectangleCollider* rc = new RectangleCollider();
				BOOST_FOREACH(ptree::value_type &v, val.second.get_child("")) {
					std::string label = v.first;
					if (label == "size") {
						rc->setSize(v.second.get<float>("x", 10.0f), v.second.get<float>("y", 10.0f));
					} 
					else if (label == "overlappable") {
						rc->setOverlappable(val.second.get<bool>(label, true));
					}
					else if (label == "transform") {
						XmlTransformParser tranParser;
						rc->setTransform(tranParser.loadTransform(v));
					}
					else if (label == "physicMaterial") {
						XmlPhysicsMaterialParser pmParser;
						rc->setPhysicMaterial( pmParser.loadPhysicMaterial(v) );
					}
				}
				return rc;
			}
			return NULL;
		}
	};

}


#endif // !_XML_RECTANGLE_COLLIDER_PARSER_H_
