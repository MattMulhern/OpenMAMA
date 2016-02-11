#!/usr/bin/env python2.7
import optparse
import platform
from subprocess import CalledProcessError, check_call
import os
from glob import glob

BUILDER_VER = 0.1
# CI_GTEST_PATTERN="-MamaTimerTestCPP*:MamaPublisherTest*"
CI_GTEST_PATTERN="-MamaPublisherTest*"
def parse_args():
    parser = optparse.OptionParser()
    parser.add_option("-b", "--bld-dir", type="string", default=None,
                      help='Build Directory to use.')
    parser.add_option("-m", "--middleware", type="string", default=None,
                      help='Middleware(s) to build (comma seperated list).')
    parser.add_option("-p", "--payload", type="string", default=None,
                      help='Payload to use in unit tests.')
    parser.add_option("-i", "--payload-id", type="string", default=None,
                      help='Payload ID used in unit tests.')
    parser.add_option("--gtest-home", type="string", default=None,
                      help='Path to gtest libraries.')
    parser.add_option("--qpid-home", type="string", default=None,
                      help='Path to proton libraries.')
    parser.add_option("--avis-home", type="string", default=None,
                      help='Path to avis libraries.')
    parser.add_option("--msbld", action="store_true", default=False,
                      help='Force msbld build.')
    parser.add_option("--verbose", action="store_true", default=False,
                      help='Verbose build logging.')
    (opts, args) = parser.parse_args()
    return opts


def run_scons(opts):
    print ("Using SCons...")
    cmdline = ["scons", "debug=True"]
    if opts.bld_dir:
        cmdline.append("blddir={0}".format(opts.bld_dir))

    if opts.middleware:
        cmdline.append("middleware={0}".format(opts.middleware))

    if opts.gtest_home:
        cmdline.append("gtest_home={0}".format(opts.gtest_home))

    if opts.qpid_home:
        cmdline.append("qpid_home={0}".format(opts.qpid_home))

    if opts.avis_home:
        cmdline.append("avis_home={0}".format(opts.avis_home))

    if opts.verbose:
        cmdline.append("verbose=True")

    try:
        print "Running: {0}".format(" ".join(cmdline))
        check_call(cmdline)
    except CalledProcessError as e:
        print "Build returned {0}. Check SCons output for details.".format(e.returncode)


def run_msbld(opts):
    print ("Not yet implemented!")


def run_gtest(opts):
    print "Running unit tests..."
    remenv = os.environ.copy()
    install_dir = os.path.abspath(glob("openmama_install*")[0])  # Assumes default install location!

    remenv["WOMBAT_PATH"]     = install_dir
    remenv["LD_LIBRARY_PATH"] = os.path.join(install_dir, "lib")

    for test in glob("{0}/bin/UnitTest*".format(install_dir)):
        cmdline = [os.path.abspath(test), "-m", "{0}".format(opts.middleware), "-p", opts.payload, "-i", opts.payload_id, "--gtest_filter={0}".format(CI_GTEST_PATTERN)]

        print "Running: {0}".format(" ".join(cmdline))
        try:
            check_call(cmdline, shell=False, env=remenv)
        except CalledProcessError as e:
            print "Test returned {0} : {1}".format(e.returncode, cmdline)
            import sys; sys.exit(1)
    import pdb; pdb.set_trace()


def main():
    opts = parse_args()
    if 'Linux' in platform.system():
        run_scons(opts)
    elif platform.system() == 'Windows':
        if opts.msbld:
            run_msbld(opts)
        else:
            run_scons(opts)
    else:
        raise EnvironmentError("No platform detected!")

    if opts.gtest_home:
        run_gtest(opts)

if __name__ == '__main__':
    main()
