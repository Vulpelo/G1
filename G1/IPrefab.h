#pragma once

#ifndef _IPREFAB_H_
#define _IPREFAB_H_

#include <variant>
#include <map>
#include <string>

namespace G1 {
	typedef typename std::variant<bool, int, float, std::string> prefabArg;
	typedef typename std::map<std::string, prefabArg> prefabArgs;

	class IPrefab {
	};

}


#endif // !_IPREFAB_H_
