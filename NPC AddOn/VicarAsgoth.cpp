#pragma hdrstop
#include "VicarAsgoth.h"

VicarAsgoth::VicarAsgoth()
{}

VicarAsgoth::~VicarAsgoth()
{}

extern NPCstructure::NPC VicarAsgothNPC;

void VicarAsgoth::Create(){
  npc = VicarAsgothNPC;
  SET_NPC_NAME( "[12780]Vicar Asgoth" );
  npc.InitialPos.X = 0;
  npc.InitialPos.Y = 0; 
	npc.InitialPos.world = 0;
}

void VicarAsgoth::OnDeath( UNIT_FUNC_PROTOTYPE )
{
    INIT_HANDLER
	if( target != NULL )
	{


		IF ((CheckFlag(__FLAG_ADDON_CRYSTAL_KEY) == 0) && (CheckItem(__OBJ_CRYSTAL_ASGOTH) ==0))
			SHOUT(INTL( 12672, "No, it cannot be!!! AAAAAARRRRRGH!"))
			PRIVATE_SYSTEM_MESSAGE(INTL( 12673, "As the vicar's body hits the floor, a small key-shaped crystal falls out of its hand."))
			PRIVATE_SYSTEM_MESSAGE(INTL( 12674, "You pick up the crystal key."))
			GiveItem(__OBJ_CRYSTAL_ASGOTH) 
		ENDIF	

	}
    CLOSE_HANDLER
NPCstructure::OnDeath( UNIT_FUNC_PARAM );
}

void VicarAsgoth::OnAttack( UNIT_FUNC_PROTOTYPE )
{
	switch(rnd(0, 20))
	{
		case 0: SHOUT(INTL( 12675, "You cannot kill what is already dead!")); break;
		case 1:
			SHOUT(INTL( 12676, "Servants of corruption, attack!"));
			SUMMON("Roaming Corpse", FROM_NPC(rnd.roll(dice(1, 5))-3,X), FROM_NPC(rnd.roll(dice(1, 5))-3,Y));
			SUMMON("Roaming Cadaver", FROM_NPC(rnd.roll(dice(1, 5))-2,X), FROM_NPC(rnd.roll(dice(1, 5))-2,Y));
            break;
		default: break;
	}

NPCstructure::OnAttack( UNIT_FUNC_PARAM );
}