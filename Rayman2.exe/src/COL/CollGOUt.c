#include "COL/CollGOUt.h"
#include "GEO/GEO_types.h"

ACP_tdxBool __cdecl COL_fn_bGetSurfaceInGeometricObject(ACP_tdxHandleOfObject _hGeometricObject)
{
    ACP_tdxIndex xElementIndex;

    for (xElementIndex = 0; xElementIndex < _hGeometricObject->xNbElements; xElementIndex++)
    {
        switch (_hGeometricObject->d_xListOfElementsTypes[xElementIndex])
        {
            case GEO_C_xElementIndexedTriangles:
            case GEO_C_xElementSpheres:
            case GEO_C_xElementAlignedBoxes:
                return TRUE;
        }
    }

    return FALSE;
}

ACP_tdxBool __cdecl COL_fn_bGetSphereAndPointOnlyInGeometricObject(ACP_tdxHandleOfObject _hGeometricObject)
{
    ACP_tdxIndex                     xElementIndex;
    GEO_tdstElementIndexedTriangles *p_stElementIndexedTriangles;
    GEO_tdstElementAlignedBoxes     *p_stElementAlignedBoxes;

    for (xElementIndex = 0; xElementIndex < _hGeometricObject->xNbElements; xElementIndex++)
    {
        switch (_hGeometricObject->d_xListOfElementsTypes[xElementIndex])
        {
            case GEO_C_xElementIndexedTriangles:
                p_stElementIndexedTriangles =
                    (GEO_tdstElementIndexedTriangles *)(_hGeometricObject->d_stListOfElements[xElementIndex]);
                if (p_stElementIndexedTriangles->xNbFaces > 0)
                {
                    return FALSE;
                }
            break;

            case GEO_C_xElementAlignedBoxes:
                p_stElementAlignedBoxes =
                    (GEO_tdstElementAlignedBoxes *)(_hGeometricObject->d_stListOfElements[xElementIndex]);
                if (p_stElementAlignedBoxes->xNbAlignedBoxes > 0)
                {
                    return FALSE;
                }
            break;

            default:
            break;
        }
    }

    return TRUE;
}
