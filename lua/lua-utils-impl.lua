--lua的一些常用函数的实现
--skyshaw

--把一个array分拆
function unpack (t, i)
    i  = i or 1
    if t[i] then 
        return t[i], unpack(t, i + 1)
    end
end

--遍历list所有元素值的一个iterator
function values (t)
    local i = 0
    return function () i = i + 1; return t[i] end
end

--traverse all the words from the current input file
function allwords ()
    local line = io.read()
    local pos = 1
    return function ()
        while line do
            local s, e = string.find(line, "%w+", pos)
            if s then
                pos = e + 1
                return string.sub(line, s, e)
            else
                line = io.read()
                pos = 1
            end
        end
        return nil
    end
end

local function iter (a, i)
    i = i + 1
    local v = a[i]
    if v then
        return i, v
    end
end

function ipairs (a)
    return iter, a, 0
end

function pairs (t)
    return next, t, nil
end

local function getnext (list,  node)
    return not node and list or node.next
end

function traverse (list) return getnext, list, nil end


--f是字符串表示，如t.x.y
function getfield (f)
    local v = _G
    for w in string.gmatch(f, "[%w]+") do
        v = v[w]
    end
    return v
end

--同上
function setfield (f, v)
    local t = _G
    for w, d in string.gmatch(f, "([%w_]+)(.?)") do
        if d == "."  then
            t[w] = t[w] or {}
            t = t[w]
        else
            t[w] = v
        end
    end
end

--[[
--require的大致过程，这里的findloader并不是这个名字，或其他形式，
--这里只是抽象的说法
function require (name)
    print("hello world")
    if not package.loaded[name] then
        local loader = findloader(name)
        if loader == nil then
            error("unable to load module" .. name)
        end
        package.loaded[name] = true
        local res = loader(name)
        if res ~= nil then
            package.loaded[name] = res
        end
    end
    return package.loaded[name]
end
--]]
