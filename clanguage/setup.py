from distutils.core import setup, Extension
import time
MOD = 'Extest'
setup(name=MOD, ext_modules=[
    Extension(MOD, sources=['ExtestWrappers.c'])
])
