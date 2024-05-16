MirageTower_1F_MapScripts:: @ 823AD01
    map_script MAP_SCRIPT_ON_TRANSITION, MirageTower_1F_OnTransition
    .byte 0
	
MirageTower_1F_OnTransition: @ 823AD07
    compare VAR_PETALBURG_GYM_STATE, 4
    call_if_eq Set_Petalburg_Flag
    setflag FLAG_ENTERED_MIRAGE_TOWER
    setflag FLAG_FORCE_MIRAGE_TOWER_VISIBLE
    setflag FLAG_LANDMARK_MIRAGE_TOWER
    end

Set_Petalburg_Flag::
        setvar VAR_PETALBURG_GYM_STATE, 6
        return

