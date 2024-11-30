#pragma once
#include "Random.h"
#include <chrono>
#include <random>

namespace Random
{
	//我们可以使用内置函数Random::get()获取随机数生成器对象，也可以直接访问全局随机数对象mt
	
	//种子生成函数，理论上应该返回std::seeq_seq，但这个类型无法复制，我们只能使用它来播种一个随机数对象，并返回其生成的随机值作为种子
	inline std::mt19937 generate()
	{
		std::random_device rd{};
		//使用1个时间种子和7个系统种子初始化种子库
		std::seed_seq ss{ static_cast<std::seed_seq::result_type>(std::chrono::steady_clock::now().time_since_epoch().count()),rd(),rd(),rd(),rd(),rd(),rd(),rd() };
		return std::mt19937{ ss };
	}

	//唯一的全局mt19937对象
	inline std::mt19937 mt{ generate() };//定义全局mt19937随机对象，我们希望使用std::random_device，std::seed_seq等进行初始化，他们没法被塞到一个表达式中，因此我们定义辅助播种函数generate()
	//mt()是mt.operator()的简写

	//int指定范围随机数生成器
	inline int get(int min, int max)
	{
		return std::uniform_int_distribution{ min,max }(mt);
		/*
		std::uniform_int_distribution range{ min,max };
		return range(mt);
		*/
		//两者是等效的，std::random_device{}()允许我们在不创建命名函数或命名变量的情况下获得相同的结果，因此更加简洁，这个()对该临时对象调用operator()
	}

	//用于获取两个相同类型范围的随机数，不一定是int类型，返回相同的类型
	template <typename T>
	T get(T min, T max)
	{
		return std::uniform_int_distribution<T>{min, max}(mt);
	}

	//用于获取两个不同类型范围的随机数，不一定是int类型，返回显示指定的返回类型，如Random::get<std::size_t>(0, 6)返回size_t类型
	template <typename R, typename S, typename T>
	R get(S min, T max)
	{
		return get<R>(static_cast<R>(min), static_cast<R>(max));
	}
}