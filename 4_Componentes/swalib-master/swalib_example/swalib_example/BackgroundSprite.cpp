#include "BackgroundSprite.h"
#include "../../common/core.h"
#include "../../common/sys.h"


void BackgroundSprite::Draw() {
	for (int i = 0; i <= SCR_WIDTH / 128; i++) {
		for (int j = 0; j <= SCR_HEIGHT / 128; j++) {
			CORE_RenderCenteredSprite(vec2(i * 128.f + 64.f, j * 128.f + 64.f), vec2(128.f, 128.f), *GetGfx());
		}
	}
}