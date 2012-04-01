function g:hguard()
        let s:hname = bufname("%") "当前bufname的名字，也就是当前编辑的文件的文件名 
        let s:pos = strridx(s:hname, ".")
    if s:pos == -1
        let s:pos = strlen(s:hname)
    endif
    let s:name = strpart(s:hname, 0, s:pos)
    let s:upper_name = toupper(s:name)
    let s:guard = "_" . s:upper_name . "_H_"
    "let s:_header = "#ifndef " . s:guard . "\n#define " . s:guard
    let s:_header_ifn = "#ifndef " . s:guard 
    let s:_header_def = '#define ' . s:guard
    let s:_footer  = "#endif"
    call append(0, s:_header_def)
    call append(0, s:_header_ifn)
    call append(line('$'), s:_footer)
endfunction 
