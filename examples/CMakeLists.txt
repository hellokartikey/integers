find_package(integers)

function(hk_example EXAMPLE_NAME)
  add_executable(${EXAMPLE_NAME} ${EXAMPLE_NAME}.cc)
  target_link_libraries(${EXAMPLE_NAME} hk::integers)
endfunction()

hk_example(1-simple)
