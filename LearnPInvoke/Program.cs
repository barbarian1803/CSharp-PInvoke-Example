// See https://aka.ms/new-console-template for more information

using System.Runtime.InteropServices;
using LearnPInvoke;

var o = new DllCustomResolver();

var obj = InteropObject.object_create("Test from C#");
var objNamePtr = InteropObject.object_get_name(obj);
var objName = Marshal.PtrToStringAnsi(objNamePtr);
Console.WriteLine($"Obj name: {objName}");
InteropObject.object_set_name(obj, "New name for object");
var objNamePtr2 = InteropObject.object_get_name(obj);
var objName2 = Marshal.PtrToStringAnsi(objNamePtr2);
Console.WriteLine($"Obj name: {objName2}");
InteropObject.free_memory(objNamePtr);
InteropObject.free_memory(objNamePtr2);
InteropObject.delete_oject(obj);