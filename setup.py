#!/usr/bin/python2

from distutils.core import setup, Extension

module1 = Extension('bed',
                    sources = ['src/bed_.c'])

setup (name = 'PackageName',
       version = '1.0',
       description = 'This is a demo package',
       ext_modules = [module1])
