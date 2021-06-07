add_test( AlgoTest.B_Search /mnt/g/Umer/Projects/Data_Structure/bin/unit_tests [==[--gtest_filter=AlgoTest.B_Search]==] --gtest_also_run_disabled_tests)
set_tests_properties( AlgoTest.B_Search PROPERTIES WORKING_DIRECTORY /mnt/g/Umer/Projects/Data_Structure/test LABELS unit)
set( unit_tests_TESTS AlgoTest.B_Search)
