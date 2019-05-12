#pragma once

#ifndef _ISPAWNABLE_H_
#define _ISPAWNABLE_H_

namespace G1 {

	class ISpawnable {
	public:
		/// <summary>Creates new GameObject in the game and returns pointer to it</summary>
		template<class T>
		T* instantiate();
		virtual ~ISpawnable() {};
	};
	template<class T>
	T * ISpawnable::instantiate()
	{
		static_assert(std::is_base_of<GameObject, T>::value, "instantiate<T>: T must inherit from GameObject");

		T* obj = new T();
		GameObjectsData::addInstantiate(obj);
		return obj;
	}
}

#endif // !_ISPAWNABLE_H_
