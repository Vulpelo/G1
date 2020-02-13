#pragma once

#ifndef _XML_CIRCLE_COLLIDER_PARSER_H_
#define _XML_CIRCLE_COLLIDER_PARSER_H_

#include "IXmlComponentParser.h"
#include "XmlTransfromParser.h"
#include "XmlPhysicMaterialParser.h"

#include "CircleCollider.h"

#include <boost/foreach.hpp>

namespace G1 {

	class XmlCircleColliderParser : public IXmlComponentParser {
	public:
		Component* load(boost::property_tree::ptree::value_type& val) {
			using namespace boost::property_tree;

			if (val.second.get("<xmlattr>.type", "") == "rectangleCollider") {
				CircleCollider* cc = new CircleCollider();
				BOOST_FOREACH(ptree::value_type &v, val.second.get_child("")) {
					std::string label = v.first;
					if (label == "overlappable") {
						cc->setOverlappable(val.second.get<bool>(label, true));
					}
					else if (label == "radious") {
						cc->setRadious(val.second.get<float>(label, 10.f));
					}
					else if (label == "transform") {
						XmlTransformParser tranParser;
						cc->setTransform(tranParser.loadTransform(v));
					}
					else if (label == "physicMaterial") {
						XmlPhysicsMaterialParser pmParser;
						cc->setPhysicMaterial(pmParser.loadPhysicMaterial(v));
					}

				}
				return cc;
			}
			return NULL;
		}
	};

}


#endif // !_XML_CIRCLE_COLLIDER_PARSER_H_
