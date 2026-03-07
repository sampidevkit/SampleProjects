# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "")
  file(REMOVE_RECURSE
  "F:\\SampleProjects\\AVRDU\\AVRDU\\out\\AVRDU\\default.cmf"
  "F:\\SampleProjects\\AVRDU\\AVRDU\\out\\AVRDU\\default.hex"
  "F:\\SampleProjects\\AVRDU\\AVRDU\\out\\AVRDU\\default.hxl"
  "F:\\SampleProjects\\AVRDU\\AVRDU\\out\\AVRDU\\default.mum"
  "F:\\SampleProjects\\AVRDU\\AVRDU\\out\\AVRDU\\default.o"
  "F:\\SampleProjects\\AVRDU\\AVRDU\\out\\AVRDU\\default.sdb"
  "F:\\SampleProjects\\AVRDU\\AVRDU\\out\\AVRDU\\default.sym"
  )
endif()
