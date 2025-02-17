add_library(TorqueLibHeaders INTERFACE)

target_include_directories(TorqueLibHeaders
  INTERFACE
    include)

target_compile_definitions(TorqueLibHeaders
  INTERFACE
    TORQUE_CPU_X86)

if(MSVC)
  target_compile_definitions(TorqueLibHeaders
    INTERFACE
      TORQUE_SUPPORTS_VC_INLINE_X86_ASM)
elseif(APPLE)
  target_compile_definitions(TorqueLibHeaders
    INTERFACE
      TORQUE_COMPILER_GCC)
endif()

add_library(TorqueLib STATIC
  TorqueLib.cpp
  math/mAngAxis.cpp
  math/mathUtils.cpp
  math/mBox.cpp
  math/mEase.cpp
  math/mMath_C.cpp
  math/mMathAMD.cpp
  math/mMathSSE.cpp
  math/mMatrix.cpp
  math/mOrientedBox.cpp
  math/mPlane.cpp
  math/mPlaneTransformer.cpp
  math/mPoint.cpp
  math/mQuat.cpp
  math/mRandom.cpp
  math/mRect.cpp
  math/mSolver.cpp
  math/mSphere.cpp
  math/util/quadTransforms.cpp

  include/TorqueLib/audio/audio.h
  include/TorqueLib/collision/collision.h
  include/TorqueLib/console/codeBlock.h
  include/TorqueLib/console/console.h
  include/TorqueLib/console/consoleFunctions.h
  include/TorqueLib/console/consoleInternal.h
  include/TorqueLib/console/consoleObject.h
  include/TorqueLib/console/scriptObject.h
  include/TorqueLib/console/simBase.h
  include/TorqueLib/console/simDictionary.h
  include/TorqueLib/core/bitSet.h
  include/TorqueLib/core/bitStream.h
  include/TorqueLib/core/color.h
  include/TorqueLib/core/dataChunker.h
  include/TorqueLib/core/dnet.h
  include/TorqueLib/core/fileio.h
  include/TorqueLib/core/fileObject.h
  include/TorqueLib/core/fileStream.h
  include/TorqueLib/core/findMatch.h
  include/TorqueLib/core/resManager.h
  include/TorqueLib/core/stream.h
  include/TorqueLib/core/stringTable.h
  include/TorqueLib/core/tVector.h
  include/TorqueLib/dgl/dgl.h
  include/TorqueLib/dgl/gBitmap.h
  include/TorqueLib/dgl/gFont.h
  include/TorqueLib/dgl/gTexManager.h
  include/TorqueLib/dgl/materialList.h
  include/TorqueLib/editor/editTSCtrl.h
  include/TorqueLib/editor/worldEditor.h
  include/TorqueLib/game/camera.h
  include/TorqueLib/game/demoGame.h
  include/TorqueLib/game/fx/explosion.h
  include/TorqueLib/game/fx/particleEngine.h
  include/TorqueLib/game/game.h
  include/TorqueLib/game/gameBase.h
  include/TorqueLib/game/gameConnection.h
  include/TorqueLib/game/item.h
  include/TorqueLib/game/marble/marble.h
  include/TorqueLib/game/net/httpObject.h
  include/TorqueLib/game/net/tcpObject.h
  include/TorqueLib/game/net/net.h
  include/TorqueLib/game/shadow.h
  include/TorqueLib/game/shapeBase.h
  include/TorqueLib/game/showTSShape.h
  include/TorqueLib/game/trigger.h
  include/TorqueLib/game/tsStatic.h
  include/TorqueLib/gui/containers/guiWindowCtrl.h
  include/TorqueLib/gui/controls/guiBitmapCtrl.h
  include/TorqueLib/gui/controls/guiBorderButton.h
  include/TorqueLib/gui/controls/guiCheckBoxCtrl.h
  include/TorqueLib/gui/controls/guiMLTextCtrl.h
  include/TorqueLib/gui/controls/guiMLTextEditCtrl.h
  include/TorqueLib/gui/core/guiCanvas.h
  include/TorqueLib/gui/core/guiControl.h
  include/TorqueLib/gui/core/guiTSControl.h
  include/TorqueLib/gui/core/guiTypes.h
  include/TorqueLib/Interface.h
  include/TorqueLib/interior/interior.h
  include/TorqueLib/interior/interiorInstance.h
  include/TorqueLib/interior/interiorRes.h
  include/TorqueLib/interior/pathedInterior.h
  include/TorqueLib/math/mAngAxis.h
  include/TorqueLib/math/mathUtils.h
  include/TorqueLib/math/mBox.h
  include/TorqueLib/math/mBoxBase.h
  include/TorqueLib/math/mConstants.h
  include/TorqueLib/math/mEase.h
  include/TorqueLib/math/mMath.h
  include/TorqueLib/math/mMathFn.h
  include/TorqueLib/math/mMathIo.h
  include/TorqueLib/math/mMatrix.h
  include/TorqueLib/math/mOrientedBox.h
  include/TorqueLib/math/mPlane.h
  include/TorqueLib/math/mPlaneSet.h
  include/TorqueLib/math/mPlaneTransformer.h
  include/TorqueLib/math/mPoint2.h
  include/TorqueLib/math/mPoint3.h
  include/TorqueLib/math/mPoint4.h
  include/TorqueLib/math/mQuat.h
  include/TorqueLib/math/mRandom.h
  include/TorqueLib/math/mRandomDeck.h
  include/TorqueLib/math/mRandomSet.h
  include/TorqueLib/math/mRect.h
  include/TorqueLib/math/mSilhouetteExtractor.h
  include/TorqueLib/math/mSphere.h
  include/TorqueLib/math/mTransform.h
  include/TorqueLib/math/util/quadTransforms.h
  include/TorqueLib/platform/event.h
  include/TorqueLib/platform/gameInterface.h
  include/TorqueLib/platform/platform.h
  include/TorqueLib/platform/platformAssert.h
  include/TorqueLib/platform/platformVideo.h
  include/TorqueLib/platformMacCarb/macCarbConsole.h
  include/TorqueLib/platformWin32/platformWin32.h
  include/TorqueLib/sceneGraph/sceneGraph.h
  include/TorqueLib/sceneGraph/sceneState.h
  include/TorqueLib/sim/netConnection.h
  include/TorqueLib/sim/netObject.h
  include/TorqueLib/sim/pathManager.h
  include/TorqueLib/sim/sceneObject.h
  include/TorqueLib/terrain/sky.h
  include/TorqueLib/terrain/sun.h
  include/TorqueLib/ts/tsMesh.h
  include/TorqueLib/ts/tsShape.h
  include/TorqueLib/TypeInfo.h 
  include/TorqueLib/game/net/net.h 
  include/TorqueLib/collision/abstractPolyList.h)

target_include_directories(TorqueLib
  PRIVATE
    include/TorqueLib/math
    include/TorqueLib/math/util)

target_link_libraries(TorqueLib
  PUBLIC
    MBExtenderHeaders
	TorqueLibHeaders)
