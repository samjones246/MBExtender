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

#include <MBExtender/MBExtender.h>
#include <TorqueLib/console/console.h>

MBX_MODULE(ASLHelper);

bool initPlugin(MBX::Plugin &plugin)
{
	MBX_INSTALL(plugin, ASLHelper);
	return true;
}

class ASLHelper {
    public:
        static int state;
        static int levelid;
        static int leveltime;
        static int totaltime;
};

int ASLHelper::state = 0;
int ASLHelper::levelid = 0;
int ASLHelper::leveltime = 0;
int ASLHelper::totaltime = 0;

MBX_CONSOLE_FUNCTION(ASL_setState, void, 2, 2, "ASL_setState(state)")
{
    ASLHelper::state = atoi(argv[1]);
}

MBX_CONSOLE_FUNCTION(ASL_setLevelId, void, 2, 2, "ASL_setLevelId(levelid)")
{
    ASLHelper::levelid = atoi(argv[1]);
}

MBX_CONSOLE_FUNCTION(ASL_setLevelTime, void, 2, 2, "ASL_setLevelTime(leveltime)")
{
    ASLHelper::leveltime = atoi(argv[1]);
}

MBX_CONSOLE_FUNCTION(ASL_setTotalTime, void, 2, 2, "ASL_setTotalTime(totaltime)")
{
    ASLHelper::totaltime = atoi(argv[1]);
}

