#!/usr/bin/lua
--simple remove
function remove_comment(str)
  local pos = str:find('//')
  if pos then
    str = str:sub(str, 1, pos - 1)
  end
  str = str:gsub("/%*.*%*/", "")
  return str
end


function st2dot(lines)
  for i, v in ipairs(lines) do
    lines[i] = remove_comment(lines[i])
  end
  local s, e = lines[1], lines[#lines]
  local pos = s:find('typedef')
  local header
  if pos then
    header = s:sub(pos + string.len('typedef')):gsub('{', ''):gsub('^%s*', ''):gsub('%s*$', '')
  else
    header = s:gsub('{', ''):gsub('^%s*', ''):gsub('%s*$', '')
  end
  e = e:gsub('}', ''):gsub(';', ''):gsub('^%s*', ''):gsub('%s*$', '')
  if e ~= "" then 
    header = e .. '(' .. header .. ')'
  end
  local label = '"' .. header .. ' |'
  cnt = 0
  for i = 2, #lines - 1 do
    line = lines[i]:gsub(';', ''):gsub('{', ''):gsub('^%s*', ''):gsub('%s*$', '')
    if line ~= "" then 
      label = label .. string.format(' f<%d> %s\\l |', i - 2, line)
    end
  end
  return label .. '"'
end

local lines = {}
for line in io.lines() do
  lines[#lines + 1] = line
end
print(st2dot(lines))
