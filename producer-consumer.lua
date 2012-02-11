
function send (x)
    coroutine.yield(x)
end

producer = coroutine.create(
    function ()
        while true do
            local x = io.read()
            send(x)
        end
    end)

function receive()
    local status, value = coroutine.resume(producer)
    return value
end

function consumer ()
    while true do
        local x = receive()
        io.write(x, "\n");
    end
end

consumer()

