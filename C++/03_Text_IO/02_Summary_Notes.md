# 总结

注意格式：
    vector<float> V1;                       // task9,动态创建vector，注意格式(堆)
    array<float, 3> A1;                     // task9,静态创造array，注意格式(栈)

    Pizza *pizza_tmep = new Pizza;          // task7
    CandyBar *apple_temp = new CandyBar[3]; // task8,动态创建数组，注意格式

    delete pizza_tmep;   // task7
    delete[] apple_temp; // task8,动态删除数组，注意格式


注意事项：
    cin >> name_temp; // valid,会自动逃过缓冲区第一个回车符
    getline(cin, dessert_temp); // valid，but a problem with getline() 不会跳过第一个回车符