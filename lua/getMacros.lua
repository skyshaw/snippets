require "myio"
function macro(line)
  if line:find("^%s*#define") then
    return true
  else
    return false
  end
end

function line_continue(line)
  if line:find("\\%s*") then
    return true
  else
    return false
  end
end

function get_macros(path, out)
  local f = assert(io.open(path), "r")
  while true do
    local line = f:read("*line")
    if not line then
      break
    end
    if macro(line) then
      out:write("\n[" .. path .. "]\n")
      out:write(line .. "\n")
      while line_continue(line) do
        line = f:read("*line")
        out:write(line .. "\n")  
      end
    end
  end
  f:close()
end 

local out = assert(io.open("out.macro", "w"))
local allpath = myio.get_path_r("./macro");
for _, path in pairs(allpath) do
  get_macros(path, out)
end
out:close()
