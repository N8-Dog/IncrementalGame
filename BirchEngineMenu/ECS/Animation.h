#pragma once

struct Animation {


	Animation() {}
	Animation(int i, int f, int s): index(i), frames(f), speed(s) {
	
	}

	int index;
	int frames;
	int speed;
};