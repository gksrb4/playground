import click
import re
import json
import os

sub_names = ['*.smi', '*.srt']
movie_names = ['*.mp4', '*.mov', '*.wmv', '*.avi', '*.avchd', '*.flv', '*.f4v', '*.swf', '*.mkv', '*.webm']

is_subtitle_name = False

def find_movie_files(files):
    global movie_names
    mv = []
    for f in files:
        # print(f)
        for exn in movie_names:
            # print(f'file: {f}, exn: {exn[1:]}')
            if exn[1:] in f:
                mv.append(f)
                break
    print(mv)
    return mv

def find_sub_files(files):
    global sub_names
    sb = []
    for f in files:
        for exn in sub_names:
            # print(exn[1:])
            if exn[1:] in f:
                sb.append(f)
                break
    print(sb)
    return sb


def get_ep_number(file):
    names = file.split('-')
    print(names)
    num = names[1][5:]
    return int(num)

def get_sub_file(subs, ep_num, movie_file):
    movie_name = movie_file[:movie_file.rfind('.')]
    for f in subs:
        sub_name = f[:f.rfind('.')]
        if sub_name == movie_name:
            return f
        splits = f.split('.')
        ep = splits[1][4:]
        try:
            if int(ep) == ep_num:
                return f
        except Exception as e:
            print(e)
    return None

def find_pair_files(files):
    movies = find_movie_files(files)
    subs = find_sub_files(files)
    pair = []
    for m in movies:
        ep = get_ep_number(m)
        sub = get_sub_file(subs, ep, m)
        if sub is None:
            print(f'\r{m} sub not found')
        pair.append((m, sub))
    print(pair)
    return pair

def get_subtitile_file(pair):
    pass

def rename_file(pair):
    pass


@click.command()
@click.option('--dir', default='.', help='directory to changing name')
@click.option('--name', help='target name')
def main(dir, name):
    global is_subtitle_name
    if name == 'sub':
        is_subtitle_name = True
    files = os.walk(dir)
    # print(files)
    path = None
    for f in files:
        print(f'---------------------\n{f}')
        path = f[0]
        files = f[2]
    pairs = find_pair_files(files)
    for p in pairs:
        mv = p[0]
        sub = p[1]
        sub_ex_name = sub[sub.rfind('.'):]
        mv_name = mv[:mv.rfind('.')]
        new_sub = mv_name+sub_ex_name
        print(f'change name\r"{sub}" -> "{new_sub}"')
        os.rename(path+'/'+sub, path+'/'+new_sub)

if __name__ == '__main__':
    main()