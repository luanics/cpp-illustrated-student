# Source code for the luanics tutorial

list(APPEND TutorialSources basics/getting_started.cpp)
list(APPEND TutorialSources basics/statements.cpp)
list(APPEND TutorialSources basics/building.cpp)
list(APPEND TutorialSources basics/variables.cpp)
list(APPEND TutorialSources basics/directives.cpp)
list(APPEND TutorialSources basics/objects.cpp)
list(APPEND TutorialSources basics/references.cpp)
list(APPEND TutorialSources basics/grid.cpp)

list(APPEND TutorialSources more_basics/functions.cpp)

list(APPEND TutorialSources more_basics/control_flow.cpp)
list(APPEND TutorialSources more_basics/expressions.cpp)

list(APPEND TutorialSources tutorial_main.cpp)

add_executable(tutorial ${TutorialSources})
target_link_libraries(tutorial luanics pthread)
set_target_properties(tutorial PROPERTIES OUTPUT_NAME tutorial${BUILD_POSTFIX})
