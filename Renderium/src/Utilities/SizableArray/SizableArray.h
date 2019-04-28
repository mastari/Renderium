#pragma once

struct SizableArray {
public:
	SizableArray(float* data, int size);
	float* data;
	unsigned int size;
};