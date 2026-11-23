#if !defined(__WP_WAYPOINT_HANDLE_TYPES__)
#define __WP_WAYPOINT_HANDLE_TYPES__

typedef struct WP_tdstGraph_ *WP_tdHandleOfGraph;

typedef struct WP_tdstWayPoint_* WP_tdhWayPoint;
#define WP_C_hWayPointInvalid ((WP_tdhWayPoint)0)
#define C_SectionWayPointDescription "WayPoint"
#define C_SubSectionIsolateWayPointDescription "Isolate"
#define C_SubSectionInWayWayPointDescription "InWay"
#define C_ScriptWayPointSuffixe "wp"

#define C_SectionWPGraphDescription "WPGraph"
#define C_SectionWPSommetDescription "WPSommet"

#endif
