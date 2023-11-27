using System.Reflection;
using System.Runtime.InteropServices;

namespace LearnPInvoke;

public class DllCustomResolver
{
    public DllCustomResolver()
    {
        NativeLibrary.SetDllImportResolver(typeof(DllCustomResolver).Assembly, ImportResolver);
    }

    private static IntPtr ImportResolver(string libraryName, Assembly assembly, DllImportSearchPath? searchpath)
    {
        IntPtr libHandle = IntPtr.Zero;
        string libraryPath = GetLibraryPath();
        if (!File.Exists(libraryPath)) throw new FileNotFoundException(libraryPath);

        libHandle = NativeLibrary.Load(libraryPath);

        return libHandle;
    }
    
    private static string GetLibraryPath()
    {
        var assemblyDir = Path.GetDirectoryName(Assembly.GetExecutingAssembly().Location)!;
        var libDir = Path.Combine(assemblyDir, "native/lib");
        const string filename = "libObjectWrapper.dylib";

        return Path.Combine(libDir, filename);
    }
}