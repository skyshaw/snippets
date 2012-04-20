function fibonacci(n)
  return coroutine.wrap(function ()
    a, b = 1, 1
    while a < n do
      coroutine.yield(a)
      a, b = b, a + b
    end
  end)
end
for num in fibonacci(10000) do
    print(num)
end
