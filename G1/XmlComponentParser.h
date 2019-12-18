#pragma once

#ifndef _XML_COMPONENT_PARSER_H_
#define _XML_COMPONENT_PARSER_H_

#include "IXmlComponentParser.h"
#include "XmlSpriteParser.h"
#include "XmlRectangleColliderParser.h"
#include "XmlRigidbodyParser.h"
#include "XmlCircleColliderParser.h"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>

namespace G1 {

	class XmlComponentParser : public IXmlComponentParser {
		std::list<IXmlComponentParser*> parsers;

	public:
		XmlComponentParser() {
			parsers.push_back(new XmlSpriteParser());
			parsers.push_back(new XmlRectangleColliderParser());
			parsers.push_back(new XmlCircleColliderParser());
			parsers.push_back(new XmlRigidbodyParser());
		}
		Component* load(boost::property_tree::ptree::value_type& val) {
			for each (IXmlComponentParser* parser in parsers)
			{
				auto component = parser->load(val);
				if (component) {
					return component;
				}
			}
			return NULL;
		}
	};

}


#endif // !_XML_COMPONENT_PARSER_H_
