#pragma once

#ifndef _IXML_COMPONENT_PARSER_H_
#define _IXML_COMPONENT_PARSER_H_

#include "Component.h"

#include <string>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

namespace G1 {

	class IXmlComponentParser {
	public:
		virtual Component* load(boost::property_tree::ptree::value_type& val) = 0;
	};

}

#endif // !_IXML_COMPONENT_PARSER_H_
