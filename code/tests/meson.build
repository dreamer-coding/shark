if get_option('with_test').enabled()
    run_command(['python3', 'tools' / 'generate-runner.py'], check: true)

    test_c   = ['unit_runner.c']
    test_cases = [
        'sample',
        'move',
        'copy',
        'delete',
        'list',
        'search',
        'rename',
        'compare',
    ]

    foreach cases : test_cases
        test_c += ['cases' / 'test_' + cases + '.c']
    endforeach

    pizza_c = executable('testbed-c', test_c, include_directories: dir,
        dependencies: [dependency('fossil-test'), app_dep])

    test('fossil testing C', pizza_c)
endif