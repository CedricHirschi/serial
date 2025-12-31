if(UNIX)
    # Serial port tests (Unix only, uses openpty)
    add_executable(${PROJECT_NAME}-test unix_serial_tests.cc)
    target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME} GTest::gtest GTest::gtest_main)
    if(NOT APPLE)
        target_link_libraries(${PROJECT_NAME}-test util)
    endif()
    add_test(NAME ${PROJECT_NAME}-test COMMAND ${PROJECT_NAME}-test)

    if(NOT APPLE)  # timer tests are unreliable on macOS
        add_executable(${PROJECT_NAME}-test-timer unit/unix_timer_tests.cc)
        target_link_libraries(${PROJECT_NAME}-test-timer ${PROJECT_NAME} GTest::gtest GTest::gtest_main)
        add_test(NAME ${PROJECT_NAME}-test-timer COMMAND ${PROJECT_NAME}-test-timer)
    endif()
endif()

# Windows tests
if(WIN32)
    add_executable(${PROJECT_NAME}-test-win win_serial_tests.cc)
    target_link_libraries(${PROJECT_NAME}-test-win ${PROJECT_NAME} GTest::gtest GTest::gtest_main)
    add_test(NAME ${PROJECT_NAME}-test-win COMMAND ${PROJECT_NAME}-test-win)
endif()
