//-----------------------------------------------------------------------------
// ASLHelper.cpp
//
// Copyright (c) 2022 Sam Jones
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files(the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//-----------------------------------------------------------------------------
// ASLHelper
// Makes it more convenient for an ASL autosplitter to interface with the game by
// storing useful values in low level statics rather than torquescript level variables.
//-----------------------------------------------------------------------------
#include <MBExtender/MBExtender.h>
#include <TorqueLib/console/console.h>
#include <string>

using namespace std;

MBX_MODULE(ASLHelper);

bool initPlugin(MBX::Plugin &plugin)
{
	MBX_INSTALL(plugin, ASLHelper);
	return true;
}

class ASLHelper {
    public:
        static int state;
        static string levelName;
        static bool playing;
        static bool loading;
        static int levelTimeMillis;
        static int totalTimeMillis;
};

int ASLHelper::state = 0;
string ASLHelper::levelName = "";
bool ASLHelper::playing = false;
bool ASLHelper::loading = false;
int ASLHelper::levelTimeMillis = 0;
int ASLHelper::totalTimeMillis = 0;

MBX_CONSOLE_FUNCTION(ASL_setState, void, 2, 2, "ASL_setState(state)")
{
    int state = 0;
    if (strcmp(argv[1], "start") == 0) {
        state = 1;
    } else if (strcmp(argv[1], "go") == 0) {
        state = 2;
    } else if (strcmp(argv[1], "end") == 0) {
        state = 3;
    }
    ASLHelper::state = state;
    TGE::Con::printf("[ASLHelper] State set to %s (%d)", argv[1], state);
}

MBX_CONSOLE_FUNCTION(ASL_setLevelName, void, 2, 2, "ASL_setLevelName(levelName)")
{
    ASLHelper::levelName = argv[1];
    TGE::Con::printf("[ASLHelper] Level ID set to %s", argv[1]);
}

MBX_CONSOLE_FUNCTION(ASL_setPlaying, void, 2, 2, "ASL_setPlaying(playing)")
{
    bool playing = false;
    if (strcmp(argv[1], "true") == 0 || atoi(argv[1]) == 1) {
        playing = true;
    }
    ASLHelper::playing = playing;
    TGE::Con::printf("[ASLHelper] Playing set to %s", argv[1]);
}

MBX_CONSOLE_FUNCTION(ASL_setLoading, void, 2, 2, "ASL_setLoading(loading)")
{
    bool loading = false;
    if (strcmp(argv[1], "true") == 0 || atoi(argv[1]) == 1) {
        loading = true;
    }
    ASLHelper::loading = loading;
    TGE::Con::printf("[ASLHelper] Loading set to %s", argv[1]);
}

MBX_CONSOLE_FUNCTION(ASL_setLevelTimeMillis, void, 2, 2, "ASL_setLevelTimeMillis(levelTimeMillis)")
{
    int levelTimeMillis = 0;
    levelTimeMillis = atoi(argv[1]);
    ASLHelper::levelTimeMillis = levelTimeMillis;
    TGE::Con::printf("[ASLHelper] Level time set to %d", levelTimeMillis);
}

MBX_CONSOLE_FUNCTION(ASL_setTotalTimeMillis, void, 2, 2, "ASL_setTotalTimeMillis(totalTimeMillis)")
{
    int totalTimeMillis = 0;
    totalTimeMillis = atoi(argv[1]);
    ASLHelper::totalTimeMillis = totalTimeMillis;
    TGE::Con::printf("[ASLHelper] Total time set to %d", totalTimeMillis);
}

