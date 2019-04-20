#pragma once

#ifndef _ISpawnable_H_
#define _ISpawnable_H_

namespace G1 {

	class ISpawnable {
		virtual void instantiate(ISpawnable* spawnable) = 0;
	};

}

#endif // !_ISpawnable_H_
