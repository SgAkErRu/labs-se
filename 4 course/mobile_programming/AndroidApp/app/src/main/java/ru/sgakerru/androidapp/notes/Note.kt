package ru.sgakerru.androidapp.notes

class Note
{
    var noteId: String? = null;
    var title: String;
    var content: String;

    constructor(noteId: String?, title: String, content: String)
    {
        this.noteId = noteId;
        this.title = title;
        this.content = content;
    }
}