ADD_EXECUTABLE(TinyRogue
        Action/Action.hpp
        Action/AttackAction.cpp
        Action/AttackAction.hpp
        Action/ItemAction.cpp
        Action/ItemAction.hpp
        Action/MonsterAction.cpp
        Action/MonsterAction.hpp
        Action/WalkAction.cpp
        Action/WalkAction.hpp

        Fov/Fov.cpp
        Fov/Fov.hpp
        Fov/LightGridData.cpp
        Fov/LightGridData.hpp
        Fov/Sector.cpp
        Fov/Sector.hpp

        Game/Console.cpp
        Game/Console.hpp
        Game/Game.cpp
        Game/Game.hpp
        Game/GameObject.cpp
        Game/GameObject.hpp
        Game/MessageLog.cpp
        Game/MessageLog.hpp
        Game/Player.cpp
        Game/Player.hpp
        Game/Status.cpp
        Game/Status.hpp

        Graphics/BloomEffect.cpp
        Graphics/BloomEffect.hpp
        Graphics/Color.hpp
        Graphics/PostEffect.cpp
        Graphics/PostEffect.hpp

        Map/Dungeon.cpp
        Map/Dungeon.hpp
        Map/Map.cpp
        Map/MapGenerator.cpp
        Map/MapGenerator.hpp
        Map/Map.hpp
        Map/Tile.hpp

        States/Help.cpp
        States/Help.hpp
        States/Inventory.cpp
        States/Inventory.hpp
        States/Play.cpp
        States/Play.hpp
        States/State.cpp
        States/State.hpp
        States/StateStack.cpp
        States/StateStack.hpp
        States/ThrowOrZap.cpp
        States/ThrowOrZap.hpp
        States/Title.cpp
        States/Title.hpp

        Utility/Direction.cpp
        Utility/Direction.hpp
        Utility/ResourceManager.cpp
        Utility/ResourceManager.hpp
        Utility/Rng.cpp
        Utility/Rng.hpp
        Utility/Rng.inl
        Utility/Utility.cpp
        Utility/Utility.hpp
        Utility/WindowsHelper.cpp
        Utility/WindowsHelper.hpp

        World/Actor.cpp
        World/Actor.hpp
        World/ActorPlayer.cpp
        World/ActorPlayer.hpp
        World/Effect.cpp
        World/Effect.hpp
        World/Entity.cpp
        World/Entity.hpp
        World/Item.cpp
        World/Item.hpp
        World/Level.cpp
        World/Level.hpp
        World/Trap.cpp
        World/Trap.hpp
        World/World.cpp
        World/World.hpp

        World/Items/Armor.cpp
        World/Items/Armor.hpp
        World/Items/Potion.cpp
        World/Items/Potion.hpp
        World/Items/Ring.cpp
        World/Items/Ring.hpp
        World/Items/Scroll.cpp
        World/Items/Scroll.hpp
        World/Items/Stick.cpp
        World/Items/Stick.hpp
        World/Items/Weapon.cpp
        World/Items/Weapon.hpp

        Main.cpp
        )

# Locate the SFML library
FIND_PACKAGE(SFML 2.5 COMPONENTS graphics window audio system REQUIRED)

# Defined by FindSDL: SDL_FOUND, if false, do not try to link to SDL
IF (NOT SFML_FOUND)
    MESSAGE(FATAL_ERROR "Cannot found SFML Version 2.5")
ENDIF ()

TARGET_COMPILE_DEFINITIONS(TinyRogue PRIVATE DORYEN_RENDERER_SFML_25=1)
TARGET_LINK_LIBRARIES(TinyRogue PRIVATE sfml-graphics sfml-window sfml-audio sfml-system)

FILE(COPY ../Shaders/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Shaders/)
FILE(COPY ../Images/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Images/)
FILE(COPY ../Fonts/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Fonts/)
FILE(COPY ../Sound/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Sound/)