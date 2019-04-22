#pragma once

#ifndef _ISPAWNABLE_H_
#define _ISPAWNABLE_H_

namespace G1 {

	class ISpawnable {
		virtual void instantiate(ISpawnable* spawnable) = 0;
	};

}

#endif // !_ISPAWNABLE_H_
