#ifndef DNM_TYPES_H
#define DNM_TYPES_H

#include "MTH/MTH_types.h"
#include "MTH/MTH3D.h"
#include "DNM/DNM_globals.h"

typedef struct DNM_tdstDynamics_ DNM_tdstDynamics;

#define DNM_C_Animation            0x00000001UL
#define DNM_C_Collide              0x00000002UL
#define DNM_C_Gravity              0x00000004UL
#define DNM_C_Tilt                 0x00000008UL
#define DNM_C_Gi                   0x00000010UL
#define DNM_C_OnGround             0x00000020UL
#define DNM_C_Climb                0x00000040UL
#define DNM_C_CollisionControl     0x00000080UL
#define DNM_C_KeepWallSpeedZ       0x00000100UL
#define DNM_C_SpeedLimit           0x00000200UL
#define DNM_C_Inertia              0x00000400UL
#define DNM_C_Stream               0x00000800UL
#define DNM_C_StickOnPlatform      0x00001000UL
#define DNM_C_Scale                0x00002000UL
#define DNM_C_AbsoluteImposeSpeed  0x00004000UL
#define DNM_C_AbsoluteProposeSpeed 0x00008000UL
#define DNM_C_AbsoluteAddSpeed     0x00010000UL
#define DNM_C_ImposeSpeedX         0x00020000UL
#define DNM_C_ImposeSpeedY         0x00040000UL
#define DNM_C_ImposeSpeedZ         0x00080000UL
#define DNM_C_ProposeSpeedX        0x00100000UL
#define DNM_C_ProposeSpeedY        0x00200000UL
#define DNM_C_ProposeSpeedZ        0x00400000UL
#define DNM_C_AddSpeedX            0x00800000UL
#define DNM_C_AddSpeedY            0x01000000UL
#define DNM_C_AddSpeedZ            0x02000000UL
#define DNM_C_LimitX               0x04000000UL
#define DNM_C_LimitY               0x08000000UL
#define DNM_C_LimitZ               0x10000000UL
#define DNM_C_ImposeRotation       0x20000000UL
#define DNM_C_LockPlatform         0x40000000UL
#define DNM_C_ImposeTranslation    0x80000000UL

#define DNM_C_BaseSize             0x00000001UL
#define DNM_C_AdvancedSize         0x00000002UL
#define DNM_C_ComplexSize          0x00000004UL
#define DNM_C_Reservated           0x00000008UL
#define DNM_C_MechanicChange       0x00000010UL
#define DNM_C_PlatformCrash        0x00000020UL
#define DNM_C_CanFall              0x00000040UL
#define DNM_C_Init                 0x00000080UL
#define DNM_C_Spider               0x00000100UL
#define DNM_C_Shoot                0x00000200UL
#define DNM_C_SafeValid            0x00000400UL
#define DNM_C_ComputeInvertMatrix  0x00000800UL
#define DNM_C_ChangeScale          0x00001000UL
#define DNM_C_Exec                 0x00002000UL
#define DNM_C_CollisionReport      0x00004000UL
#define DNM_C_NoGravity            0x00008000UL
#define DNM_C_Stop                 0x00010000UL
#define DNM_C_SlidingGround        0x00020000UL
#define DNM_C_Always               0x00040000UL
#define DNM_C_Crash                0x00080000UL
#define DNM_C_Swim                 0x00100000UL
#define DNM_C_NeverFall            0x00200000UL
#define DNM_C_Hanging              0x00400000UL
#define DNM_C_WallAdjust           0x00800000UL
#define DNM_C_ActorMove            0x01000000UL
#define DNM_C_ForceSafeWalk        0x02000000UL
#define DNM_C_DontUseNewMechanic   0x04000000UL

#define DNM_M_ulFlags(p)                (DNM_M_pstGetBaseBlock(p)->ulFlags)
#define DNM_M_ulEndFlags(p)             (DNM_M_pstGetBaseBlock(p)->ulEndFlags)

#ifndef TRUE
#define TRUE    1
#endif
#ifndef FALSE
#define FALSE   0
#endif
#define DNM_M_bDynamicsIsAnimation(_p_stDynamics) (DNM_M_ulFlags(_p_stDynamics) & DNM_C_Animation ? TRUE: FALSE)
#define DNM_M_bDynamicsIsCollide(_p_stDynamics) (DNM_M_ulFlags(_p_stDynamics) & DNM_C_Collide ? TRUE: FALSE)
#define DNM_M_bDynamicsIsGravity(_p_stDynamics) (DNM_M_ulFlags(_p_stDynamics) & DNM_C_Gravity ? TRUE: FALSE)

#define DNM_M_bDynamicsIsActorMove(_p_stDynamics) (DNM_M_ulEndFlags(_p_stDynamics) & DNM_C_ActorMove ? TRUE: FALSE)
#define DNM_M_bDynamicsIsTilt(_p_stDynamics) (DNM_M_ulFlags(_p_stDynamics) & DNM_C_Tilt ? TRUE: FALSE)
#define DNM_M_bDynamicsIsGi(_p_stDynamics) (DNM_M_ulFlags(_p_stDynamics) & DNM_C_Gi ? TRUE: FALSE)
#define DNM_M_bDynamicsIsOnGround(_p_stDynamics) (DNM_M_ulFlags(_p_stDynamics) & DNM_C_OnGround ? TRUE: FALSE)
#define DNM_M_bDynamicsIsClimb(_p_stDynamics) (DNM_M_ulFlags(_p_stDynamics) & DNM_C_Climb ? TRUE: FALSE)
#define DNM_M_bDynamicsIsSpider(_p_stDynamics) (DNM_M_ulEndFlags(_p_stDynamics) & DNM_C_Spider ? TRUE: FALSE)
#define DNM_M_bDynamicsIsShoot(_p_stDynamics) (DNM_M_ulEndFlags(_p_stDynamics) & DNM_C_Shoot ? TRUE: FALSE)
#define DNM_M_bDynamicsIsCollisionControl(_p_stDynamics) (DNM_M_ulFlags(_p_stDynamics) & DNM_C_CollisionControl ? TRUE: FALSE)
#define DNM_M_bDynamicsIsKeepWallSpeedZ(_p_stDynamics) (DNM_M_ulFlags(_p_stDynamics) & DNM_C_KeepWallSpeedZ ? TRUE: FALSE)
#define DNM_M_bDynamicsIsSpeedLimit(_p_stDynamics) (DNM_M_ulFlags(_p_stDynamics) & DNM_C_SpeedLimit ? TRUE: FALSE)
#define DNM_M_bDynamicsIsInertia(_p_stDynamics) (DNM_M_ulFlags(_p_stDynamics) & DNM_C_Inertia ? TRUE: FALSE)
#define DNM_M_bDynamicsIsStream(_p_stDynamics) (DNM_M_ulFlags(_p_stDynamics) & DNM_C_Stream ? TRUE: FALSE)
#define DNM_M_bDynamicsIsStickOnPlatform(_p_stDynamics) (DNM_M_ulFlags(_p_stDynamics) & DNM_C_StickOnPlatform ? TRUE: FALSE)
#define DNM_M_bDynamicsIsScale(_p_stDynamics) (DNM_M_ulFlags(_p_stDynamics) & DNM_C_Scale ? TRUE: FALSE)
#define DNM_M_bDynamicsIsRelativeImposeSpeed(_p_stDynamics) (!(DNM_M_ulFlags(_p_stDynamics) & DNM_C_AbsoluteImposeSpeed) ? TRUE: FALSE)
#define DNM_M_bDynamicsIsRelativeProposeSpeed(_p_stDynamics) (!(DNM_M_ulFlags(_p_stDynamics) & DNM_C_AbsoluteProposeSpeed) ? TRUE: FALSE)
#define DNM_M_bDynamicsIsRelativeAddSpeed(_p_stDynamics) (!(DNM_M_ulFlags(_p_stDynamics) & DNM_C_AbsoluteAddSpeed) ? TRUE: FALSE)
#define DNM_M_bDynamicsIsImposeSpeedX(_p_stDynamics) (DNM_M_ulFlags(_p_stDynamics) & DNM_C_ImposeSpeedX ? TRUE: FALSE)
#define DNM_M_bDynamicsIsImposeSpeedY(_p_stDynamics) (DNM_M_ulFlags(_p_stDynamics) & DNM_C_ImposeSpeedY ? TRUE: FALSE)
#define DNM_M_bDynamicsIsImposeSpeedZ(_p_stDynamics) (DNM_M_ulFlags(_p_stDynamics) & DNM_C_ImposeSpeedZ ? TRUE: FALSE)
#define DNM_M_bDynamicsIsProposeSpeedX(_p_stDynamics) (DNM_M_ulFlags(_p_stDynamics) & DNM_C_ProposeSpeedX ? TRUE: FALSE)
#define DNM_M_bDynamicsIsProposeSpeedY(_p_stDynamics) (DNM_M_ulFlags(_p_stDynamics) & DNM_C_ProposeSpeedY ? TRUE: FALSE)
#define DNM_M_bDynamicsIsProposeSpeedZ(_p_stDynamics) (DNM_M_ulFlags(_p_stDynamics) & DNM_C_ProposeSpeedZ ? TRUE: FALSE)
#define DNM_M_bDynamicsIsAddSpeedX(_p_stDynamics) (DNM_M_ulFlags(_p_stDynamics) & DNM_C_AddSpeedX ? TRUE: FALSE)
#define DNM_M_bDynamicsIsAddSpeedY(_p_stDynamics) (DNM_M_ulFlags(_p_stDynamics) & DNM_C_AddSpeedY ? TRUE: FALSE)
#define DNM_M_bDynamicsIsAddSpeedZ(_p_stDynamics) (DNM_M_ulFlags(_p_stDynamics) & DNM_C_AddSpeedZ ? TRUE: FALSE)
#define DNM_M_bDynamicsIsLimitX(_p_stDynamics) (DNM_M_ulFlags(_p_stDynamics) & DNM_C_LimitX ? TRUE: FALSE)
#define DNM_M_bDynamicsIsLimitY(_p_stDynamics) (DNM_M_ulFlags(_p_stDynamics) & DNM_C_LimitY ? TRUE: FALSE)
#define DNM_M_bDynamicsIsLimitZ(_p_stDynamics) (DNM_M_ulFlags(_p_stDynamics) & DNM_C_LimitZ ? TRUE: FALSE)
#define DNM_M_bDynamicsIsImposeRotation(_p_stDynamics) (DNM_M_ulFlags(_p_stDynamics) & DNM_C_ImposeRotation ? TRUE: FALSE)
#define DNM_M_bDynamicsIsImposeTranslation(_p_stDynamics) (DNM_M_ulFlags(_p_stDynamics) & DNM_C_ImposeTranslation ? TRUE: FALSE)
#define DNM_M_bDynamicsIsMechanicChange(_p_stDynamics) (DNM_M_ulEndFlags(_p_stDynamics) & DNM_C_MechanicChange ? TRUE: FALSE)
#define DNM_M_bDynamicsIsCanFall(_p_stDynamics) (DNM_M_ulEndFlags(_p_stDynamics) & DNM_C_CanFall ? TRUE: FALSE)
#define DNM_M_bDynamicsIsInit(_p_stDynamics) (DNM_M_ulEndFlags(_p_stDynamics) & DNM_C_Init ? TRUE: FALSE)
#define DNM_M_bDynamicsIsChangeScale(_p_stDynamics) (DNM_M_ulEndFlags(_p_stDynamics) & DNM_C_ChangeScale ? TRUE: FALSE)
#define DNM_M_bDynamicsIsBaseSize(_p_stDynamics) (DNM_M_ulEndFlags(_p_stDynamics) & DNM_C_BaseSize ? TRUE: FALSE)
#define DNM_M_bDynamicsIsAdvancedSize(_p_stDynamics) (DNM_M_ulEndFlags(_p_stDynamics) & DNM_C_AdvancedSize ? TRUE: FALSE)
#define DNM_M_bDynamicsIsComplexSize(_p_stDynamics) (DNM_M_ulEndFlags(_p_stDynamics) & DNM_C_ComplexSize ? TRUE: FALSE)
#define DNM_M_bDynamicsIsCollisionReport(_p_stDynamics) (DNM_M_ulEndFlags(_p_stDynamics) & DNM_C_CollisionReport ? TRUE: FALSE)
#define DNM_M_bDynamicsIsComputeInvertMatrix(_p_stDynamics) (DNM_M_ulEndFlags(_p_stDynamics) & DNM_C_ComputeInvertMatrix ? TRUE: FALSE)
#define DNM_M_bDynamicsIsNoGravity(_p_stDynamics) (DNM_M_ulEndFlags(_p_stDynamics) & DNM_C_NoGravity ? TRUE: FALSE)
#define DNM_M_bDynamicsIsSlidingGround(_p_stDynamics) (DNM_M_ulEndFlags(_p_stDynamics) & DNM_C_SlidingGround ? TRUE: FALSE)
#define DNM_M_bDynamicsIsAlways(_p_stDynamics) (DNM_M_ulEndFlags(_p_stDynamics) & DNM_C_Always ? TRUE: FALSE)
#define DNM_M_bDynamicsIsSwim(_p_stDynamics) (DNM_M_ulEndFlags(_p_stDynamics) & DNM_C_Swim ? TRUE: FALSE)
#define DNM_M_bDynamicsIsNeverFall(_p_stDynamics) (DNM_M_ulEndFlags(_p_stDynamics) & DNM_C_NeverFall ? TRUE: FALSE)
#define DNM_M_bDynamicsIsHanging(_p_stDynamics) (DNM_M_ulEndFlags(_p_stDynamics) & DNM_C_Hanging ? TRUE: FALSE)
#define DNM_M_bDynamicsIsWallAdjust(_p_stDynamics) (DNM_M_ulEndFlags(_p_stDynamics) & DNM_C_WallAdjust ? TRUE: FALSE)
#define DNM_M_bDynamicsIsForceSafeWalk(_p_stDynamics) (DNM_M_ulEndFlags(_p_stDynamics) & DNM_C_ForceSafeWalk ? TRUE: FALSE)
#define DNM_M_bDynamicsIsDontUseNewMechanic(_p_stDynamics) (DNM_M_ulEndFlags(_p_stDynamics) & DNM_C_DontUseNewMechanic ? TRUE: FALSE)

#define DNM_M_bDynamicsIsProposeSpeed(_p_stDynamics) (DNM_M_ulFlags(_p_stDynamics) & (DNM_C_ProposeSpeedX|DNM_C_ProposeSpeedY|DNM_C_ProposeSpeedZ) ? TRUE: FALSE)
#define DNM_M_bDynamicsIsImposeSpeed(_p_stDynamics) (DNM_M_ulFlags(_p_stDynamics) & (DNM_C_ImposeSpeedX|DNM_C_ImposeSpeedY|DNM_C_ImposeSpeedZ)  ? TRUE: FALSE)
#define DNM_M_bDynamicsIsAddSpeed(_p_stDynamics) (DNM_M_ulFlags(_p_stDynamics) & (DNM_C_AddSpeedX|DNM_C_AddSpeedY|DNM_C_AddSpeedZ) ? TRUE: FALSE)
#define DNM_M_bDynamicsIsLimit(_p_stDynamics) (DNM_M_ulFlags(_p_stDynamics) & (DNM_C_LimitX|DNM_C_LimitY|DNM_C_LimitZ) ? TRUE: FALSE)

#define DNM_M_vDynamicsSetAlways(p, _bValue) \
    do { \
        if (_bValue) DNM_M_ulEndFlags(p) |= DNM_C_Always; \
        else         DNM_M_ulEndFlags(p) &= ~DNM_C_Always; \
    } while (0)

#define DNM_M_vDynamicsSetStop(p, _bValue) \
    do { \
        if (_bValue) DNM_M_ulEndFlags(p) |= DNM_C_Stop; \
        else         DNM_M_ulEndFlags(p) &= ~DNM_C_Stop; \
    } while (0)

#define DNM_M_vDynamicsSetCrash(p, _bValue) \
    do { \
        if (_bValue) DNM_M_ulEndFlags(p) |= DNM_C_Crash; \
        else         DNM_M_ulEndFlags(p) &= ~DNM_C_Crash; \
    } while (0)

#define DNM_M_vDynamicsSetWallAdjust(p, _bValue) \
    do { \
        if (_bValue) DNM_M_ulEndFlags(p) |= DNM_C_WallAdjust; \
        else         DNM_M_ulEndFlags(p) &= ~DNM_C_WallAdjust; \
    } while (0)

#define DNM_M_vDynamicsSetForceSafeWalk(p, _bValue) \
    do { \
        if (_bValue) DNM_M_ulEndFlags(p) |= DNM_C_ForceSafeWalk; \
        else         DNM_M_ulEndFlags(p) &= ~DNM_C_ForceSafeWalk; \
    } while (0)

#define DNM_M_vDynamicsSetImposeRotation(p, _bValue) \
    do { \
        if (_bValue) DNM_M_ulFlags(p) |= DNM_C_ImposeRotation; \
        else         DNM_M_ulFlags(p) &= ~DNM_C_ImposeRotation; \
    } while (0)

#define DNM_M_vDynamicsSetImposeTranslation(p, _bValue) \
    do { \
        if (_bValue) DNM_M_ulFlags(p) |= DNM_C_ImposeTranslation; \
        else         DNM_M_ulFlags(p) &= ~DNM_C_ImposeTranslation; \
    } while (0)

#define DNM_M_vDynamicsSetAnimation(_p_stDynamics,_bValue) (DNM_M_ulFlags(_p_stDynamics) = ((_bValue) ? (DNM_M_ulFlags(_p_stDynamics) |= DNM_C_Animation) : (DNM_M_ulFlags(_p_stDynamics) &= ~DNM_C_Animation)))
#define DNM_M_vDynamicsSetCollide(_p_stDynamics,_bValue) (DNM_M_ulFlags(_p_stDynamics) = ((_bValue) ? (DNM_M_ulFlags(_p_stDynamics) |= DNM_C_Collide) : (DNM_M_ulFlags(_p_stDynamics) &= ~DNM_C_Collide)))
#define DNM_M_vDynamicsSetGravity(_p_stDynamics,_bValue) (DNM_M_ulFlags(_p_stDynamics) = ((_bValue) ? (DNM_M_ulFlags(_p_stDynamics) |= DNM_C_Gravity) : (DNM_M_ulFlags(_p_stDynamics) &= ~DNM_C_Gravity)))
#define DNM_M_vDynamicsSetTilt(_p_stDynamics,_bValue) (DNM_M_ulFlags(_p_stDynamics) = ((_bValue) ? (DNM_M_ulFlags(_p_stDynamics) |= DNM_C_Tilt) : (DNM_M_ulFlags(_p_stDynamics) &= ~DNM_C_Tilt)))
#define DNM_M_vDynamicsSetGi(_p_stDynamics,_bValue) (DNM_M_ulFlags(_p_stDynamics) = ((_bValue) ? (DNM_M_ulFlags(_p_stDynamics) |= DNM_C_Gi) : (DNM_M_ulFlags(_p_stDynamics) &= ~DNM_C_Gi)))
#define DNM_M_vDynamicsSetOnGround(_p_stDynamics,_bValue) (DNM_M_ulFlags(_p_stDynamics) = ((_bValue) ? (DNM_M_ulFlags(_p_stDynamics) |= DNM_C_OnGround) : (DNM_M_ulFlags(_p_stDynamics) &= ~DNM_C_OnGround)))
#define DNM_M_vDynamicsSetClimb(_p_stDynamics,_bValue) (DNM_M_ulFlags(_p_stDynamics) = ((_bValue) ? (DNM_M_ulFlags(_p_stDynamics) |= DNM_C_Climb) : (DNM_M_ulFlags(_p_stDynamics) &= ~DNM_C_Climb)))
#define DNM_M_vDynamicsSetSpider(_p_stDynamics,_bValue) (DNM_M_ulEndFlags(_p_stDynamics) = ((_bValue) ? (DNM_M_ulEndFlags(_p_stDynamics) |= DNM_C_Spider) : (DNM_M_ulEndFlags(_p_stDynamics) &= ~DNM_C_Spider)))
#define DNM_M_vDynamicsSetShoot(_p_stDynamics,_bValue) (DNM_M_ulEndFlags(_p_stDynamics) = ((_bValue) ? (DNM_M_ulEndFlags(_p_stDynamics) |= DNM_C_Shoot) : (DNM_M_ulEndFlags(_p_stDynamics) &= ~DNM_C_Shoot)))
#define DNM_M_vDynamicsSetCollisionControl(_p_stDynamics,_bValue) (DNM_M_ulFlags(_p_stDynamics) = ((_bValue) ? (DNM_M_ulFlags(_p_stDynamics) |= DNM_C_CollisionControl) : (DNM_M_ulFlags(_p_stDynamics) &= ~DNM_C_CollisionControl)))
#define DNM_M_vDynamicsSetKeepWallSpeedZ(_p_stDynamics,_bValue) (DNM_M_ulFlags(_p_stDynamics) = ((_bValue) ? (DNM_M_ulFlags(_p_stDynamics) |= DNM_C_KeepWallSpeedZ) : (DNM_M_ulFlags(_p_stDynamics) &= ~DNM_C_KeepWallSpeedZ)))
#define DNM_M_vDynamicsSetSpeedLimit(_p_stDynamics,_bValue) (DNM_M_ulFlags(_p_stDynamics) = ((_bValue) ? (DNM_M_ulFlags(_p_stDynamics) |= DNM_C_SpeedLimit) : (DNM_M_ulFlags(_p_stDynamics) &= ~DNM_C_SpeedLimit)))
#define DNM_M_vDynamicsSetInertia(_p_stDynamics,_bValue) (DNM_M_ulFlags(_p_stDynamics) = ((_bValue) ? (DNM_M_ulFlags(_p_stDynamics) |= DNM_C_Inertia) : (DNM_M_ulFlags(_p_stDynamics) &= ~DNM_C_Inertia)))
#define DNM_M_vDynamicsSetStream(_p_stDynamics,_bValue) (DNM_M_ulFlags(_p_stDynamics) = ((_bValue) ? (DNM_M_ulFlags(_p_stDynamics) |= DNM_C_Stream) : (DNM_M_ulFlags(_p_stDynamics) &= ~DNM_C_Stream)))
#define DNM_M_vDynamicsSetStickOnPlatform(_p_stDynamics,_bValue) (DNM_M_ulFlags(_p_stDynamics) = ((_bValue) ? (DNM_M_ulFlags(_p_stDynamics) |= DNM_C_StickOnPlatform) : (DNM_M_ulFlags(_p_stDynamics) &= ~DNM_C_StickOnPlatform)))
#define DNM_M_vDynamicsSetScaleOption(_p_stDynamics,_bValue) (DNM_M_ulFlags(_p_stDynamics) = ((_bValue) ? (DNM_M_ulFlags(_p_stDynamics) |= DNM_C_Scale) : (DNM_M_ulFlags(_p_stDynamics) &= ~DNM_C_Scale)))
#define DNM_M_vDynamicsSetSwim(_p_stDynamics,_bValue) (DNM_M_ulEndFlags(_p_stDynamics) = ((_bValue) ? (DNM_M_ulEndFlags(_p_stDynamics) |= DNM_C_Swim) : (DNM_M_ulEndFlags(_p_stDynamics) &= ~DNM_C_Swim)))
#define DNM_M_vDynamicsSetNeverFall(_p_stDynamics,_bValue) (DNM_M_ulEndFlags(_p_stDynamics) = ((_bValue) ? (DNM_M_ulEndFlags(_p_stDynamics) |= DNM_C_NeverFall) : (DNM_M_ulEndFlags(_p_stDynamics) &= ~DNM_C_NeverFall)))
#define DNM_M_vDynamicsSetDontUseNewMechanic(_p_stDynamics,_bValue) (DNM_M_ulEndFlags(_p_stDynamics) = ((_bValue) ? (DNM_M_ulEndFlags(_p_stDynamics) |= DNM_C_DontUseNewMechanic) : (DNM_M_ulEndFlags(_p_stDynamics) &= ~DNM_C_DontUseNewMechanic)))

#define DNM_M_vDynamicsSetCosSlope(p, x)         (DNM_M_xDynamicsGetCosSlope(p) = (x))
#define DNM_M_vDynamicsSetSlopeLimit(p, x)       (DNM_M_xDynamicsGetSlopeLimit(p) = (x))
#define DNM_M_vDynamicsSetGravityFactor(p, x)    (DNM_M_xDynamicsGetGravityFactor(p) = (x))
#define DNM_M_vDynamicsSetSlide(p, x)            (DNM_M_xDynamicsGetSlide(p) = (x))
#define DNM_M_vDynamicsSetRebound(p, x)          (DNM_M_xDynamicsGetRebound(p) = (x))
#define DNM_M_vDynamicsSetInertiaFactorX(p, x)   (DNM_M_xDynamicsGetInertiaFactorX(p) = (x))
#define DNM_M_vDynamicsSetInertiaFactorY(p, x)   (DNM_M_xDynamicsGetInertiaFactorY(p) = (x))
#define DNM_M_vDynamicsSetInertiaFactorZ(p, x)   (DNM_M_xDynamicsGetInertiaFactorZ(p) = (x))
#define DNM_M_vDynamicsSetMaxSpeed(p, v)         MTH3D_M_vCopyVector(DNM_M_pDynamicsGetMaxSpeed(p), (v))
#define DNM_M_vDynamicsSetStreamSpeed(_p_stDynamics,pstStreamSpeed) MTH3D_M_vCopyVector( DNM_M_pDynamicsGetStreamSpeed(_p_stDynamics), pstStreamSpeed )
#define DNM_M_vDynamicsSetCollisionTranslation(p, v) MTH3D_M_vCopyVector(DNM_M_pDynamicsGetCollisionTranslation(p), (v))
#define DNM_M_vDynamicsSetTiltIntensity(p, x)    (DNM_M_xDynamicsGetTiltIntensity(p) = (x))
#define DNM_M_vDynamicsSetTiltInertia(p, x)      (DNM_M_xDynamicsGetTiltInertia(p) = (x))
#define DNM_M_vDynamicsSetTiltOrigin(p, x)       (DNM_M_xDynamicsGetTiltOrigin(p) = (x))
#define DNM_M_vDynamicsSetStreamFactor(p, x)     (DNM_M_xDynamicsGetStreamFactor(p) = (x))
#define DNM_M_vDynamicsSetSlideFactorX(_p_stDynamics,xSlideFactorX) (DNM_M_xDynamicsGetSlideFactorX(_p_stDynamics) = xSlideFactorX)
#define DNM_M_vDynamicsSetSlideFactorY(_p_stDynamics,xSlideFactorY) (DNM_M_xDynamicsGetSlideFactorY(_p_stDynamics) = xSlideFactorY)
#define DNM_M_vDynamicsSetSlideFactorZ(_p_stDynamics,xSlideFactorZ) (DNM_M_xDynamicsGetSlideFactorZ(_p_stDynamics) = xSlideFactorZ)

#define DNM_M_p_stDynamicsGetCurrentMatrix(_p_stDynamics) (&DNM_M_pstGetBaseBlock(_p_stDynamics)->m_stCurrentMatrix)
#define DNM_M_p_stDynamicsGetPreviousMatrix(_p_stDynamics) (&DNM_M_pstGetBaseBlock(_p_stDynamics)->m_stPreviousMatrix)
#define DNM_M_p_stDynamicsGetAbsolutePreviousMatrix(_p_stDynamics) (&DNM_M_pstGetComplexBlock(_p_stDynamics)->m_stAbsolutePreviousMatrix)
#define DNM_M_p_stDynamicsGetPrevPreviousMatrix(_p_stDynamics) (&DNM_M_pstGetComplexBlock(_p_stDynamics)->m_stPrevPreviousMatrix)

#define DNM_M_p_stDynamicsGetImposeRotationMatrix(_p_stDynamics) (&DNM_M_pstGetBaseBlock(_p_stDynamics)->m_stImposeRotationMatrix)
#define DNM_M_pDynamicsGetContact(_p_stDynamics) ( &DNM_M_pstGetComplexBlock(_p_stDynamics)->m_stContact )

#define DNM_M_xDynamicsGetGravityFactor(_p_stDynamics) (DNM_M_pstGetBaseBlock(_p_stDynamics)->m_xGravity)
#define DNM_M_xDynamicsGetCosSlope(_p_stDynamics) ( DNM_M_pstGetBaseBlock(_p_stDynamics)->m_xCosSlope )
#define DNM_M_xDynamicsGetSlopeLimit(_p_stDynamics) (DNM_M_pstGetBaseBlock(_p_stDynamics)->m_xSlopeLimit)
#define DNM_M_xDynamicsGetSlide(_p_stDynamics) (DNM_M_pstGetBaseBlock(_p_stDynamics)->m_xSlide)
#define DNM_M_xDynamicsGetRebound(_p_stDynamics) (DNM_M_pstGetBaseBlock(_p_stDynamics)->m_xRebound)
#define DNM_M_pDynamicsGetImposeSpeed(_p_stDynamics) ( &DNM_M_pstGetBaseBlock(_p_stDynamics)->m_stImposeSpeed )

#define DNM_M_vDynamicsSetImposeSpeed(p, _p_v)         MTH3D_M_vCopyVector(DNM_M_pDynamicsGetImposeSpeed(p), (_p_v))
#define DNM_M_vDynamicsSetProposeSpeed(p, _p_v)        MTH3D_M_vCopyVector(DNM_M_pDynamicsGetProposeSpeed(p), (_p_v))
#define DNM_M_vDynamicsSetAddSpeed(p, _p_v)            MTH3D_M_vCopyVector(DNM_M_pDynamicsGetAddSpeed(p), (_p_v))
#define DNM_M_pDynamicsGetProposeSpeed(_p_stDynamics) ( &DNM_M_pstGetBaseBlock(_p_stDynamics)->m_stProposeSpeed )
#define DNM_M_pDynamicsGetPreviousSpeed(_p_stDynamics) ( &DNM_M_pstGetBaseBlock(_p_stDynamics)->m_stPreviousSpeed )

#define DNM_M_vDynamicsSetPreviousSpeed(p, _p_v)       MTH3D_M_vCopyVector(DNM_M_pDynamicsGetPreviousSpeed(p), (_p_v))
#define DNM_M_pDynamicsGetFallTranslation(_p_stDynamics) ( &DNM_M_pstGetComplexBlock(_p_stDynamics)->m_stFallTranslation )
#define DNM_M_vDynamicsSetFallTranslation(p, _p_v)     MTH3D_M_vCopyVector(DNM_M_pDynamicsGetFallTranslation(p), (_p_v))
#define DNM_M_p_stDynamicsGetSpeedAnim(_p_stDynamics) (&DNM_M_pstGetBaseBlock(_p_stDynamics)->m_stSpeedAnim)
#define DNM_M_pDynamicsGetSafeTranslation(_p_stDynamics) ( &DNM_M_pstGetBaseBlock(_p_stDynamics)->m_stSafeTranslation )
#define DNM_M_pDynamicsGetAddTranslation(_p_stDynamics) ( &DNM_M_pstGetBaseBlock(_p_stDynamics)->m_stAddTranslation )
#define DNM_M_xDynamicsGetInertiaFactorX(_p_stDynamics) (DNM_M_pstGetAdvancedBlock(_p_stDynamics)->m_xInertiaX)
#define DNM_M_xDynamicsGetInertiaFactorY(_p_stDynamics) (DNM_M_pstGetAdvancedBlock(_p_stDynamics)->m_xInertiaY)
#define DNM_M_xDynamicsGetInertiaFactorZ(_p_stDynamics) (DNM_M_pstGetAdvancedBlock(_p_stDynamics)->m_xInertiaZ)
#define DNM_M_xDynamicsGetSlideFactorX(_p_stDynamics) ( DNM_M_pstGetAdvancedBlock(_p_stDynamics)->m_xSlideFactorX )
#define DNM_M_xDynamicsGetSlideFactorY(_p_stDynamics) ( DNM_M_pstGetAdvancedBlock(_p_stDynamics)->m_xSlideFactorY )
#define DNM_M_xDynamicsGetSlideFactorZ(_p_stDynamics) ( DNM_M_pstGetAdvancedBlock(_p_stDynamics)->m_xSlideFactorZ )
#define DNM_M_xDynamicsGetStreamPriority(_p_stDynamics) (DNM_M_pstGetAdvancedBlock(_p_stDynamics)->m_xStreamPrority)
#define DNM_M_xDynamicsGetStreamFactor(_p_stDynamics) (DNM_M_pstGetAdvancedBlock(_p_stDynamics)->m_xStreamFactor)
#define DNM_M_xDynamicsGetPreviousSlide(_p_stDynamics) ( DNM_M_pstGetAdvancedBlock(_p_stDynamics)->m_xPreviousSlide )
#define DNM_M_vDynamicsSetPreviousSlide(p, _x)         (DNM_M_xDynamicsGetPreviousSlide(p) = (_x))
#define DNM_M_pDynamicsGetMaxSpeed(_p_stDynamics) (&DNM_M_pstGetAdvancedBlock(_p_stDynamics)->m_stMaxSpeed)
#define DNM_M_pDynamicsGetLimit(_p_stDynamics) ( &DNM_M_pstGetAdvancedBlock(_p_stDynamics)->m_stLimit )
#define DNM_M_pDynamicsGetStreamSpeed(_p_stDynamics) (&DNM_M_pstGetAdvancedBlock(_p_stDynamics)->m_stStreamSpeed)
#define DNM_M_pDynamicsGetAddSpeed(_p_stDynamics) ( &DNM_M_pstGetAdvancedBlock(_p_stDynamics)->m_stAddSpeed )
#define DNM_M_pDynamicsGetCollisionTranslation(_p_stDynamics) ( &(DNM_M_pstGetAdvancedBlock(_p_stDynamics)->m_stCollisionTranslation) )
#define DNM_M_pDynamicsGetInertiaTranslation(_p_stDynamics) ( &DNM_M_pstGetAdvancedBlock(_p_stDynamics)->m_stInertiaTranslation )
#define DNM_M_pDynamicsGetGroundNormal(_p_stDynamics) ( &(DNM_M_pstGetAdvancedBlock(_p_stDynamics)->m_stGroundNormal) )
#define DNM_M_pDynamicsGetWallNormal(_p_stDynamics) ( &(DNM_M_pstGetAdvancedBlock(_p_stDynamics)->m_stWallNormal) )
#define DNM_M_vDynamicsSetGroundNormal(p, _p_v)        MTH3D_M_vCopyVector(DNM_M_pDynamicsGetGroundNormal(p), (_p_v))
#define DNM_M_vDynamicsSetWallNormal(p, _p_v)          MTH3D_M_vCopyVector(DNM_M_pDynamicsGetWallNormal(p), (_p_v))

#define DNM_M_vDynamicsSetInertiaTranslation(p, _p_v)  MTH3D_M_vCopyVector(DNM_M_pDynamicsGetInertiaTranslation(p), (_p_v))
#define DNM_M_cDynamicsGetCollideCounter(_p_stDynamics) (DNM_M_pstGetAdvancedBlock(_p_stDynamics)->m_cCollideCounter)
#define DNM_M_vDynamicsSetCollideCounter(p, _c)        (DNM_M_cDynamicsGetCollideCounter(p) = (signed char)(_c))
#define DNM_M_vDynamicsDecCollideCounter(p)            (DNM_M_cDynamicsGetCollideCounter(p)--)
#define DNM_M_cDynamicsGetNbFrame(_p_stDynamics) (DNM_M_pstGetBaseBlock(_p_stDynamics)->m_ucNbFrame)
#define DNM_M_vDynamicsSetNbFrame(p, _uc)              (DNM_M_cDynamicsGetNbFrame(p) = (unsigned char)(_uc))

#define DNM_M_p_stDynamicsGetScaleX(_p_stDynamics) (MTH3D_M_xGetXofVector(&DNM_M_pstGetBaseBlock(_p_stDynamics)->m_stScale))
#define DNM_M_p_stDynamicsGetScaleY(_p_stDynamics) (MTH3D_M_xGetYofVector(&DNM_M_pstGetBaseBlock(_p_stDynamics)->m_stScale))
#define DNM_M_p_stDynamicsGetScaleZ(_p_stDynamics) (MTH3D_M_xGetZofVector(&DNM_M_pstGetBaseBlock(_p_stDynamics)->m_stScale))

#define DNM_M_xDynamicsGetTiltAngle(_p_stDynamics) ( DNM_M_pstGetComplexBlock(_p_stDynamics)->m_xTiltAngle )
#define DNM_M_xDynamicsGetTiltOrigin(_p_stDynamics) (DNM_M_pstGetComplexBlock(_p_stDynamics)->m_xTiltOrigin)
#define DNM_M_xDynamicsGetTiltIntensity(_p_stDynamics) (DNM_M_pstGetComplexBlock(_p_stDynamics)->m_xTiltIntensity)
#define DNM_M_xDynamicsGetTiltInertia(_p_stDynamics) (DNM_M_pstGetComplexBlock(_p_stDynamics)->m_xTiltInertia)
#define DNM_M_vDynamicsSetTiltAngle(p, _x)             (DNM_M_xDynamicsGetTiltAngle(p) = (_x))

#define DNM_M_xDynamicsGetHangingLimit(_p_stDynamics) ( DNM_M_pstGetComplexBlock(_p_stDynamics)->m_xHangingLimit )
#define DNM_M_vDynamicsSetHangingLimit(p, _x)          (DNM_M_xDynamicsGetHangingLimit(p) = (_x))

struct HIE_tdstSuperObject;
#define DNM_M_hDynamicsGetPlatformSO(_p_stDynamics) ( DNM_M_pstGetComplexBlock(_p_stDynamics)->m_hPlatform )
#define DNM_M_vDynamicsSetPlatformSO(p, _hPlatform)    (DNM_M_hDynamicsGetPlatformSO(p) = (_hPlatform))

#ifndef DNM_C_LockPlatform
#define DNM_C_LockPlatform         0x40000000UL
#endif
#define DNM_M_bDynamicsIsLockPlatform(p)               ((DNM_M_ulFlags(p) & DNM_C_LockPlatform) != 0)
#define DNM_M_bDynamicsSetLockPlatform(p, _b)          DNM_M_vDynamicsSetBitInFlags_(p, DNM_C_LockPlatform, _b)

typedef struct DNM_stMecMatCharacteristics {
    MTH_tdxReal m_xSlide;
    MTH_tdxReal m_xRebound;
} DNM_tdstMecMatCharacteristics;

typedef struct DNM_stMecObstacle {
    MTH_tdxReal       m_xRate;
    MTH3D_tdstVector  m_stNorm;
    MTH3D_tdstVector  m_stContact;
    void             *hMyMaterial;
    void             *hCollidedMaterial;
    void             *mp_stSupObj;
    unsigned long     m_eType;
    signed short      m_xMyEntity;
    signed short      m_xCollidedEntity;
    MTH3D_tdstVector  m_stTranslation;
    MTH3D_tdstVector  m_stZoneMove;
    MTH3D_tdstVector  m_stZonePosition;
    MTH_tdxReal       m_xZoneRadius;
    DNM_tdstMecMatCharacteristics m_stProperties;
    DNM_tdstMecMatCharacteristics m_stMyProperties;
} DNM_tdstMecObstacle;
typedef char DNM_ct_assert_MecObstacle[(sizeof(DNM_tdstMecObstacle) == 0x68) ? 1 : -1];

#define DNM_ObsType_Nothing      0x0
#define DNM_ObsType_Scenery      0x1
#define DNM_ObsType_Mobile       0x2
#define DNM_ObsType_DoubleEdge   0x4
#define DNM_ObsType_MobileWall   0x9

#define DNM_M_xObstacleGetRate(o)                      ((o)->m_xRate)
#define DNM_M_p_stObstacleGetNorm(o)                   (&(o)->m_stNorm)
#define DNM_M_p_stObstacleGetContact(o)                (&(o)->m_stContact)
#define DNM_M_hObstacleGetMyMaterial(o)                ((o)->hMyMaterial)
#define DNM_M_hObstacleGetCollidedMaterial(o)          ((o)->hCollidedMaterial)
#define DNM_M_p_stObstacleGetObject(o)                 ((o)->mp_stSupObj)
#define DNM_M_eObstacleGetType(o)                      ((o)->m_eType)
#define DNM_M_xObstacleGetCollidedEntity(o)            ((o)->m_xCollidedEntity)
#define DNM_M_xObstacleSetCollidedEntity(o, _v)        (DNM_M_xObstacleGetCollidedEntity(o) = (signed short)(_v))
#define DNM_M_pObstacleGetZoneMove(o)                  (&(o)->m_stZoneMove)
#define DNM_M_pObstacleGetZonePosition(o)              (&(o)->m_stZonePosition)

#define DNM_M_MecObstacleCopyClone(_p_stDst, _p_stSrc) memcpy((_p_stDst), (_p_stSrc), sizeof(DNM_tdstMecObstacle))
#define DNM_M_p_stObstacleGetTranslation(o)            (&(o)->m_stTranslation)
#define DNM_M_xObstacleGetTranslation(o)               (&(o)->m_stTranslation)
#define DNM_M_xObstacleGetZoneRadius(o)                ((o)->m_xZoneRadius)
#define DNM_M_xObstacleGetSlide(o)                     ((o)->m_stProperties.m_xSlide)
#define DNM_M_xObstacleGetRebound(o)                   ((o)->m_stProperties.m_xRebound)

#define DNM_M_eObstacleSetType(o, _v)                  (DNM_M_eObstacleGetType(o) = (unsigned long)(_v))
#define DNM_M_xObstacleSetSlide(o, _v)                 (DNM_M_xObstacleGetSlide(o) = (MTH_tdxReal)(_v))
#define DNM_M_xObstacleSetRebound(o, _v)               (DNM_M_xObstacleGetRebound(o) = (MTH_tdxReal)(_v))

#define DNM_M_xMatCharacteristicsGetSlide(m)           ((m)->m_xSlide)
#define DNM_M_xMatCharacteristicsGetRebound(m)         ((m)->m_xRebound)
#define DNM_M_xObstacleSetRate(o, _v)                  ((o)->m_xRate = (MTH_tdxReal)(_v))
#define DNM_M_ObstacleSetNorm(o, _p_v)                 MTH3D_M_vCopyVector(&(o)->m_stNorm, (_p_v))
#define DNM_M_ObstacleSetContact(o, _p_v)              MTH3D_M_vCopyVector(&(o)->m_stContact, (_p_v))
#define DNM_M_p_stObstacleSetObject(o, _h)             ((o)->mp_stSupObj = (void *)(_h))
#define DNM_M_vObstacleSetCollidedMaterial(o, _h)      ((o)->hCollidedMaterial = (void *)(_h))
#define DNM_M_vObstacleSetMyMaterial(o, _h)            ((o)->hMyMaterial = (void *)(_h))

typedef struct DNM_stObstacle {
    MTH_tdxReal       m_xRate;
    MTH3D_tdstVector  m_stNorm;
    MTH3D_tdstVector  m_stContact;
    void             *hMyMaterial;
    void             *hCollidedMaterial;
    void             *mp_stSupObj;
} DNM_tdstObstacle;

typedef struct DNM_stReport {
    unsigned long       m_ulPrevSurfaceState;
    unsigned long       m_ulCurrSurfaceState;
    DNM_tdstObstacle    m_stObstacle;
    DNM_tdstObstacle    m_stGround;
    DNM_tdstObstacle    m_stWall;
    DNM_tdstObstacle    m_stCharacter;
    DNM_tdstObstacle    m_stWater;
    DNM_tdstObstacle    m_stCeil;
    MTH_tdstMove        m_stAbsolutePrevSpeed;
    MTH_tdstMove        m_stAbsoluteCurrSpeed;
    MTH_tdstMove        m_stAbsolutePrevPosition;
    MTH_tdstMove        m_stAbsoluteCurrPosition;
    char                m_cBitField;
} DNM_tdstReport;
typedef char DNM_ct_assert_report_size[(sizeof(DNM_tdstReport) == 0x16C) ? 1 : -1];

typedef struct DNM_stMecReport {
    unsigned long       m_ulCurrSurfaceState;
    DNM_tdstMecObstacle m_stObstacle;
    DNM_tdstMecObstacle m_stGround;
    DNM_tdstMecObstacle m_stWall;
    DNM_tdstMecObstacle m_stCharacter;
    DNM_tdstMecObstacle m_stWater;
    DNM_tdstMecObstacle m_stCeil;
} DNM_tdstMecReport;

extern DNM_tdstMecReport g_stReport;

#define DNM_M_ulReportGetSurfaceState(_p)        ((_p)->m_ulCurrSurfaceState)
#define DNM_M_ulReportSetSurfaceState(_p, _v)    (DNM_M_ulReportGetSurfaceState(_p) = (_v))
#define DNM_M_ulReportAddSurfaceState(_p, _v)    (DNM_M_ulReportGetSurfaceState(_p) |= (_v))
#define DNM_M_ulReportGetPrevSurfaceState(_p)    ((_p)->m_ulPrevSurfaceState)
#define DNM_M_ulReportSetPrevSurfaceState(_p, _v)(DNM_M_ulReportGetPrevSurfaceState(_p) = (_v))
#define DNM_M_p_stReportGetObstacle(_p)          (&(_p)->m_stObstacle)
#define DNM_M_p_stReportGetGround(_p)            (&(_p)->m_stGround)
#define DNM_M_p_stReportGetWall(_p)              (&(_p)->m_stWall)
#define DNM_M_p_stReportGetCharacter(_p)         (&(_p)->m_stCharacter)
#define DNM_M_p_stReportGetWater(_p)             (&(_p)->m_stWater)
#define DNM_M_p_stReportGetCeil(_p)              (&(_p)->m_stCeil)

#define DNM_M_MecReportSetObstacle(_p_stReport,_p_stObstacle) DNM_M_MecObstacleCopyClone(&(_p_stReport)->m_stObstacle,_p_stObstacle)
#define DNM_M_MecReportSetGround(_p_stReport,_p_stObstacle) DNM_M_MecObstacleCopyClone(&(_p_stReport)->m_stGround,_p_stObstacle)
#define DNM_M_MecReportSetWall(_p_stReport,_p_stObstacle) DNM_M_MecObstacleCopyClone(DNM_M_p_stReportGetWall(_p_stReport),_p_stObstacle)
#define DNM_M_MecReportSetCharacter(_p_stReport,_p_stObstacle) DNM_M_MecObstacleCopyClone(DNM_M_p_stReportGetCharacter(_p_stReport),_p_stObstacle)
#define DNM_M_MecReportSetWater(_p_stReport,_p_stObstacle) DNM_M_MecObstacleCopyClone(DNM_M_p_stReportGetWater(_p_stReport),_p_stObstacle)
#define DNM_M_MecReportSetCeil(_p_stReport,_p_stObstacle) DNM_M_MecObstacleCopyClone(DNM_M_p_stReportGetCeil(_p_stReport),_p_stObstacle)
#define DNM_M_p_stReportGetAbsolutePrevSpeed(_p) (&(_p)->m_stAbsolutePrevSpeed)
#define DNM_M_p_stReportGetAbsoluteCurrSpeed(_p) (&(_p)->m_stAbsoluteCurrSpeed)
#define DNM_M_p_stReportGetAbsolutePrevPosition(_p) (&(_p)->m_stAbsolutePrevPosition)
#define DNM_M_p_stReportGetAbsoluteCurrPosition(_p) (&(_p)->m_stAbsoluteCurrPosition)

#define DNM_M_ReportSetAbsoluteCurrSpeed(_p, _pMove) \
    (*DNM_M_p_stReportGetAbsoluteCurrSpeed(_p) = *(_pMove))
#define DNM_M_ReportSetAbsoluteCurrPosition(_p, _pMove) \
    (*DNM_M_p_stReportGetAbsoluteCurrPosition(_p) = *(_pMove))

#define DNM_M_p_stDynamicsGetReport(_p_stDynamics) (DNM_M_pstGetBaseBlock(_p_stDynamics)->m_pstReport)

#define DNM_M_vDynamicsSetAddTranslation(_p_stDynamics,p_stAddTranslation) MTH3D_M_vCopyVector ( DNM_M_pDynamicsGetAddTranslation(_p_stDynamics), p_stAddTranslation )
#define DNM_M_vDynamicsSetImposeRotationMatrix(_p_stDynamics,hMatrix) MTH3D_M_vCopyMatrix ( DNM_M_p_stDynamicsGetImposeRotationMatrix(_p_stDynamics), hMatrix )

#define DNM_M_vDynamicsSetActorMove(p, _bValue) \
    do { \
        if (_bValue) DNM_M_ulEndFlags(p) |= DNM_C_ActorMove; \
        else         DNM_M_ulEndFlags(p) &= ~DNM_C_ActorMove; \
    } while (0)

#define DNM_M_vDynamicsSetBitInFlags_(p, _bit, _bValue) \
    do { \
        if (_bValue) DNM_M_ulFlags(p) |= (_bit); \
        else         DNM_M_ulFlags(p) &= ~(_bit); \
    } while (0)

#define DNM_M_vDynamicsSetImposeSpeedX(p, _b)    DNM_M_vDynamicsSetBitInFlags_(p, DNM_C_ImposeSpeedX, _b)
#define DNM_M_vDynamicsSetImposeSpeedY(p, _b)    DNM_M_vDynamicsSetBitInFlags_(p, DNM_C_ImposeSpeedY, _b)
#define DNM_M_vDynamicsSetImposeSpeedZ(p, _b)    DNM_M_vDynamicsSetBitInFlags_(p, DNM_C_ImposeSpeedZ, _b)
#define DNM_M_vDynamicsSetProposeSpeedX(p, _b)   DNM_M_vDynamicsSetBitInFlags_(p, DNM_C_ProposeSpeedX, _b)
#define DNM_M_vDynamicsSetProposeSpeedY(p, _b)   DNM_M_vDynamicsSetBitInFlags_(p, DNM_C_ProposeSpeedY, _b)
#define DNM_M_vDynamicsSetProposeSpeedZ(p, _b)   DNM_M_vDynamicsSetBitInFlags_(p, DNM_C_ProposeSpeedZ, _b)
#define DNM_M_vDynamicsSetAddSpeedX(p, _b)       DNM_M_vDynamicsSetBitInFlags_(p, DNM_C_AddSpeedX, _b)
#define DNM_M_vDynamicsSetAddSpeedY(p, _b)       DNM_M_vDynamicsSetBitInFlags_(p, DNM_C_AddSpeedY, _b)
#define DNM_M_vDynamicsSetAddSpeedZ(p, _b)       DNM_M_vDynamicsSetBitInFlags_(p, DNM_C_AddSpeedZ, _b)
#define DNM_M_bDynamicsSetAbsoluteImposeSpeed(p, _b)  DNM_M_vDynamicsSetBitInFlags_(p, DNM_C_AbsoluteImposeSpeed, _b)
#define DNM_M_bDynamicsSetAbsoluteProposeSpeed(p, _b) DNM_M_vDynamicsSetBitInFlags_(p, DNM_C_AbsoluteProposeSpeed, _b)
#define DNM_M_bDynamicsSetAbsoluteAddSpeed(p, _b)     DNM_M_vDynamicsSetBitInFlags_(p, DNM_C_AbsoluteAddSpeed, _b)

#define DNM_M_vDynamicsSetBitInEndFlags_(p, _bit, _bValue) \
    do { \
        if (_bValue) DNM_M_ulEndFlags(p) |= (_bit); \
        else         DNM_M_ulEndFlags(p) &= ~(_bit); \
    } while (0)

#define DNM_M_vDynamicsSetInit(p, _b)               DNM_M_vDynamicsSetBitInEndFlags_(p, DNM_C_Init, _b)
#define DNM_M_vDynamicsSetExec(p, _b)               DNM_M_vDynamicsSetBitInEndFlags_(p, DNM_C_Exec, _b)
#define DNM_M_vDynamicsSetComputeInvertMatrix(p, _b)DNM_M_vDynamicsSetBitInEndFlags_(p, DNM_C_ComputeInvertMatrix, _b)
#define DNM_M_vDynamicsSetNoGravity(p, _b)          DNM_M_vDynamicsSetBitInEndFlags_(p, DNM_C_NoGravity, _b)
#define DNM_M_vDynamicsSetChangeScale(p, _b)        DNM_M_vDynamicsSetBitInEndFlags_(p, DNM_C_ChangeScale, _b)
#define DNM_M_vDynamicsSetSlidingGround(p, _b)      DNM_M_vDynamicsSetBitInEndFlags_(p, DNM_C_SlidingGround, _b)
#define DNM_M_bDynamicsSetMechanicChange(p, _b)     DNM_M_vDynamicsSetBitInEndFlags_(p, DNM_C_MechanicChange, _b)
#define DNM_M_bDynamicsSetPlatformCrash(p, _b)      DNM_M_vDynamicsSetBitInEndFlags_(p, DNM_C_PlatformCrash, _b)
#define DNM_M_bDynamicsSetCanFall(p, _b)            DNM_M_vDynamicsSetBitInEndFlags_(p, DNM_C_CanFall, _b)

#define DNM_M_vDynamicsSetScale(p, _xX, _xY, _xZ) \
    do { \
        DNM_M_p_stDynamicsGetScaleX(p) = (_xX); \
        DNM_M_p_stDynamicsGetScaleY(p) = (_xY); \
        DNM_M_p_stDynamicsGetScaleZ(p) = (_xZ); \
    } while (0)

typedef struct DNM_stParsingDatas
{
    MTH3D_tdstVector stPosition;
    MTH_tdxReal      xOutAlpha;
    MTH3D_tdstVector stVector;
} DNM_tdstParsingDatas;

typedef enum eDynamicSize_
{
    eDynamicSizeBase = 0,
    eDynamicSizeAdvanced = 1,
    eDynamicSizeComplex = 2
} eDynamicSize;

typedef unsigned long DNM_tdeMechanicsID;

#ifndef DNM_eBase
#define DNM_eMIC_Error  ((DNM_tdeMechanicsID)-1)
#define DNM_eCamera     ((DNM_tdeMechanicsID)0)
#define DNM_eBase       ((DNM_tdeMechanicsID)1)
#endif

#define DNM_M_pDynamicsGetCurrentIdCard(_p_stDynamics) (DNM_M_pstGetBaseBlock(_p_stDynamics)->m_pCurrentIdCard)
/* 0x419b90 */
extern DNM_tdeMechanicsID __cdecl DNM_fn_eIdentityCardGetType(void *);

typedef struct tdstDynam_
{
    DNM_tdstDynamics     *p_stDynamics;
    DNM_tdstParsingDatas *p_stParsingDatas;
    DNM_tdeMechanicsID    eUsedMechanics;
} MS_tdstDynam;

typedef MS_tdstDynam *MS_tdxHandleToDynam;

#define g_xCachedFrameLength GAM_g_xFrameLength  /* 0x50043C */

#include "MEC/dnmdynam.h"

#endif
