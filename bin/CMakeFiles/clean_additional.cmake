# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Expense_tracker_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Expense_tracker_autogen.dir\\ParseCache.txt"
  "Expense_tracker_autogen"
  )
endif()
