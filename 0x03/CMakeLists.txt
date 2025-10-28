# (C) 2025 A.Voß, a.voss@fh-aachen.de, info@codebasedlearning.dev

add_executable(a_simple_class snippets/a_simple_class.cpp)
add_executable(b_explicit_const snippets/b_explicit_const.cpp)
add_executable(c_copy_assignment snippets/c_copy_assignment.cpp)
add_executable(d_ctor_dtor_throw snippets/d_ctor_dtor_throw.cpp)
add_executable(e_getter_setter snippets/e_getter_setter.cpp)
add_executable(f_raii snippets/f_raii.cpp)

add_executable(study_aggregate snippets/study_aggregate.cpp)
add_executable(study_properties snippets/study_properties.cpp)

add_executable(luckyrock_one_solution solutions/luckyrock_one_solution.cpp)
add_executable(meadowriver_one_solution solutions/meadowriver_one_solution.cpp)
add_executable(ravencastle_one_solution solutions/ravencastle_one_solution.cpp)
add_executable(stoneridge_one_solution solutions/stoneridge_one_solution.cpp)
add_executable(coral_creek_one_solution solutions/coral_creek_one_solution.cpp)

# Custom
add_executable(ravencaste_custom custom/Ravencastle.cpp)
add_executable(stone_ridge_cusom custom/StoneRidge.cpp)
add_executable(lucky_rock_custom custom/LuckyRock.cpp)
add_executable(meadow_river_custom custom/MeadowRiver.cpp)
add_executable(coral_creek_custom custom/CoralCreek.cpp)