#*******************************************************************
# Library
#*******************************************************************

list(APPEND LuanicsLibSources crypto/caesar_cipher.cpp)
list(APPEND LuanicsLibSources crypto/helpers.cpp)
list(APPEND LuanicsLibSources crypto/vigenere_cipher.cpp)

list(APPEND LuanicsLibSources logging/level.cpp)
list(APPEND LuanicsLibSources logging/logger.cpp)
list(APPEND LuanicsLibSources logging/simple_sink.cpp)
list(APPEND LuanicsLibSources logging/simple_source.cpp)

list(APPEND LuanicsLibSources grid/dynamic_grid.cpp)
list(APPEND LuanicsLibSources grid/flipped_grid.cpp)
list(APPEND LuanicsLibSources grid/grid.cpp)
list(APPEND LuanicsLibSources grid/sub_grid.cpp)

list(APPEND LuanicsLibSources string/conversion.cpp)
list(APPEND LuanicsLibSources string/enumerated_matcher.cpp)

list(APPEND LuanicsLibSources testing/core/augmented_reporter_decorator.cpp)
list(APPEND LuanicsLibSources testing/core/composite.cpp)
list(APPEND LuanicsLibSources testing/core/first_fail_detector.cpp)
list(APPEND LuanicsLibSources testing/core/indenting_reporter.cpp)
list(APPEND LuanicsLibSources testing/core/leaf.cpp)
list(APPEND LuanicsLibSources testing/core/outcome.cpp)
list(APPEND LuanicsLibSources testing/core/reporter_augmenter.cpp)
list(APPEND LuanicsLibSources testing/core/simpler_reporter.cpp)
list(APPEND LuanicsLibSources testing/core/slow_excluder.cpp)
list(APPEND LuanicsLibSources testing/core/string_excluder.cpp)
list(APPEND LuanicsLibSources testing/core/string_matcher.cpp)
list(APPEND LuanicsLibSources testing/unit/instance.cpp)
list(APPEND LuanicsLibSources testing/unit/standard_reporter.cpp)

list(APPEND LuanicsLibSources utility/paths.cpp)
list(APPEND LuanicsLibSources utility/streams.cpp)

add_library(luanics SHARED ${LuanicsLibSources})
set_target_properties(luanics PROPERTIES OUTPUT_NAME luanics${BUILD_POSTFIX})

#*******************************************************************
# Test
#*******************************************************************

list(APPEND LuanicsTestSources crypto/test/caesar_cipher_test.cpp)
list(APPEND LuanicsTestSources crypto/test/helpers_test.cpp)
list(APPEND LuanicsTestSources crypto/test/vigenere_cipher_test.cpp)

list(APPEND LuanicsTestSources grid/test/dynamic_grid_test.cpp)
list(APPEND LuanicsTestSources grid/test/flipped_grid_test.cpp)
list(APPEND LuanicsTestSources grid/test/grid_test.cpp)
list(APPEND LuanicsTestSources grid/test/sub_grid_test.cpp)

list(APPEND LuanicsTestSources logging/test/contract_test.cpp)
list(APPEND LuanicsTestSources logging/test/simple_sink_test.cpp)
list(APPEND LuanicsTestSources logging/test/simple_source_test.cpp)
list(APPEND LuanicsTestSources logging/test/tuple_record_test.cpp)

list(APPEND LuanicsTestSources math/test/operations_test.cpp)

list(APPEND LuanicsTestSources meta/test/detection_test.cpp)
list(APPEND LuanicsTestSources meta/test/type_traits_test.cpp)

list(APPEND LuanicsTestSources string/test/enumerated_matcher_test.cpp)

list(APPEND LuanicsTestSources testing/core/test/outcome_test.cpp)
list(APPEND LuanicsTestSources testing/core/test/core_test.cpp)
list(APPEND LuanicsTestSources testing/core/test/slow_excluder_test.cpp)
list(APPEND LuanicsTestSources testing/core/test/string_excluder_test.cpp)
list(APPEND LuanicsTestSources testing/core/test/string_matcher_test.cpp)
list(APPEND LuanicsTestSources testing/tutorial/test/reporter_adapter_test.cpp)

list(APPEND LuanicsTestSources utility/test/paths_test.cpp)
list(APPEND LuanicsTestSources utility/test/tuples_test.cpp)

add_executable(luanics-test test_main.cpp ${LuanicsTestSources})
set_target_properties(luanics-test PROPERTIES OUTPUT_NAME luanics-test${BUILD_POSTFIX})
target_link_libraries(luanics-test luanics pthread)
