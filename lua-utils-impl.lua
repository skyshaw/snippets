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
