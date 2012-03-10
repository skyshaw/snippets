function receive (prod)
    local status, value = coroutine.resume(prod)
    return value
end

function send (value)
    coroutine.yield(value)
end

function producer ()
    return coroutine.create( function ()
        while true do
            local value = io.read()
            --coroutine.yield(value)
            send(value)
        end
    end)
end

function filter (prod)
    return coroutine.create(function ()
        for line = 1, math.huge do
            --local status, value = coroutine.resume(prod)
            local value = receive(prod)
            value = string.format("%5d %s", line, value)
            send(value)
        end
    end)
end

function consumer (prod)
    while true do
        local value = receive(prod)
        io.write(value, "\n")
    end
end

consumer(filter(producer()))
