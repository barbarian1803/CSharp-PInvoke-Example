using System.Runtime.InteropServices;

namespace LearnPInvoke;

public static class InteropObject
{
    private const string LibName = "Object";
    [DllImport(LibName, CallingConvention = CallingConvention.Cdecl, ExactSpelling = true)]
    public static extern IntPtr object_create(string name);
    
    [DllImport(LibName, CallingConvention = CallingConvention.Cdecl, ExactSpelling = true)]
    public static extern IntPtr object_get_name(IntPtr o);

    [DllImport(LibName, CallingConvention = CallingConvention.Cdecl, ExactSpelling = true)]
    public static extern void object_set_name(IntPtr obj, string name);

    [DllImport(LibName, CallingConvention = CallingConvention.Cdecl, ExactSpelling = true)]
    public static extern void free_memory(IntPtr s);

    [DllImport(LibName, CallingConvention = CallingConvention.Cdecl, ExactSpelling = true)]
    public static extern void delete_oject(IntPtr o);
}